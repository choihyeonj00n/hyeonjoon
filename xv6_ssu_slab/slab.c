#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "spinlock.h"
#include "slab.h"

const int slab_size[] = {16, 32, 64, 128, 256, 512, 1024, 2048};

struct {
	struct spinlock lock;
	struct slab slab[NSLAB];
} stable;

void slabinit(){

    struct slab *s;
    int slab_count = 0;

    acquire(&stable.lock);

    for(s = stable.slab; s < &stable.slab[NSLAB]; s++){

        int ssize = slab_size[slab_count];
        s->size = ssize;
        s->num_free_objects = 0;
        s->num_used_objects = 0;
        s->num_objects_per_page = 4096 / ssize;

        s->bitmap = kalloc();
		if(s->bitmap == 0){
			panic("Fail to allocate bitmap\n");
		}
		memset(s->bitmap, 0 ,PGSIZE);

		for(int i = 0; i < MAX_PAGES_PER_SLAB; i++){
			s->page[i] = 0;
		}

        slab_count++;
    }

    release(&stable.lock);
}

char *kmalloc(int size){

    struct slab *s;

    for(s = stable.slab; s < &stable.slab[NSLAB]; s++){
        if(s->size >= size){ break; }
    }

    if(s->num_free_objects == 0){
        if(s->num_pages == MAX_PAGES_PER_SLAB){
			return 0x00;
        }
        else{
			for(int i = 0; i < MAX_PAGES_PER_SLAB; i++){
				if(s->page[i] == 0){

					acquire(&stable.lock);

					s->page[i] = kalloc();
					if(s->page[i] == 0){
						panic("page allocation fail\n");
					}
					memset(s->page[i], 0, PGSIZE);

					int order = (i * s->num_objects_per_page) / 8;
					int offset = (i * s->num_objects_per_page) % 8;

					s->num_pages += 1;
					s->num_free_objects += s->num_objects_per_page - 1;
					s->num_used_objects += 1;
					s->bitmap[order] |= (1 << offset);

					release(&stable.lock);
					
					return s->page[i];
				}
			}
        }
    }
    else{
		for(int i = 0; i < MAX_PAGES_PER_SLAB; i++){
			if(s->page[i] != 0){

				int order = (i * s->num_objects_per_page) / 8;
				int next_order = ((i+1) * s->num_objects_per_page) / 8;
				int offset = (i * s->num_objects_per_page) % 8;

				if(s->size >= 1024){
					for(int j = offset; j < offset + s->num_objects_per_page; j++){
						if((s->bitmap[order] & (1 << j)) == 0x00){

							acquire(&stable.lock);

							s->num_free_objects -= 1;
							s->num_used_objects += 1;
							s->bitmap[order] |= (1 << j); 
							
							release(&stable.lock);

							return s->page[i] + ((j - offset) * s->size); 
						}
					}
				}
				else{
					for(int j = order; j < next_order; j++){
						if(s->bitmap[j] != 0xFF){
							for(int k = 0; k < 8; k++){
								if((s->bitmap[j] & (1 << k)) == 0x00){

									acquire(&stable.lock);

									s->num_free_objects -= 1;
									s->num_used_objects += 1;
									s->bitmap[j] |= (1 << k);

									release(&stable.lock);

									return s->page[i] + (((8 * j + k) % s->num_objects_per_page) * s->size);
								}
							}
						}
					}
				}
			}
		}
    }
	return 0x00;
}

void kmfree(char *addr, int size){
	struct slab *s;

	int page_index = 0;
	int page_offset = 0;

	for(s = stable.slab; s < &stable.slab[NSLAB]; s++){
		if(s->size >= size){ break; }
	}
	
	memset(addr, 0, s->size); // object's content reset
	
	for(page_index = 0; page_index < MAX_PAGES_PER_SLAB; page_index++){
		if(0 <= (addr - s->page[page_index]) && (addr - s->page[page_index]) <= PGSIZE){
			page_offset = addr - s->page[page_index];
			break;
		}
	} //To specify the object's location by using page_index and page_distance

	int spf_obj = (page_index * s->num_objects_per_page) + (page_offset / s->size);
	int obj_order = spf_obj / 8;
	int obj_offset = spf_obj % 8;

	if((s->bitmap[obj_order] & (1 << obj_offset)) != 0x00){

		acquire(&stable.lock);
	
		s->num_free_objects += 1;
		s->num_used_objects -= 1;
		s->bitmap[obj_order] &= ~(1 << obj_offset);
	
		release(&stable.lock);
	
	//============== page deallocation ================//
		int obj_start = page_index * s->num_objects_per_page;
		int obj_next = (page_index + 1) * s->num_objects_per_page;
		int obj_start_order = obj_start / 8;
		int obj_next_order = obj_next / 8;
		int obj_start_offset = obj_start % 8;
		int flag = 0; // flag 0 : page deallocation, flag 1: Not yet
	
		if(s->size >= 1024){
			for(int i = obj_start_offset; i < obj_start_offset + s->num_objects_per_page; i++){
				if((s->bitmap[obj_start_order] & (1 << i)) != 0x00){
					flag = 1;
					break;
				}
			}
		}
		else{
			for(int i = obj_start_order; i < obj_next_order; i++){
				if(s->bitmap[i] != 0x00){
					flag = 1;
					break;
				}
			}
		}
	
		if(flag == 0){
	
			acquire(&stable.lock);
	
			s->num_pages -= 1;
			s->num_free_objects -= s->num_objects_per_page;
			kfree(s->page[page_index]);
			s->page[page_index] = 0;
	
			release(&stable.lock);
		}
	}
}

/* Helper functions */
void slabdump(){
	cprintf("==================================== slabdump ========================================\n");

	struct slab *s;

	cprintf("size\tnum_pages\tused_objects\tfree_objects\tbitmap[0]\tpage[0]\n");

	for(s = stable.slab; s < &stable.slab[NSLAB]; s++){
		cprintf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
			s->size, s->num_pages, s->num_used_objects, s->num_free_objects, s->bitmap[0], *(s->page[0]));
	}
}

int numobj_slab(int slabid)
{
	return stable.slab[slabid].num_used_objects;
}

int numpage_slab(int slabid)
{
	return stable.slab[slabid].num_pages;
}
