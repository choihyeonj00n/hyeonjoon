#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAX_size 10

struct node
{
		int item;
		struct node *next;
};

struct circularlinkedlist
{
		struct node head;
		struct node *tail;
		int num_items;
};

typedef struct node node_t;
typedef struct circularlinkedlist circular_t;

int main()
{
		char buffer[MAX_size];
		for(int i = 100; i <= 1000; i += 100){
				FILE *linkbench = fopen("linkbench.trc", "r");
				if(linkbench == NULL){
						printf("failed to read file\n");
						return 1;
				}
				int tot_cnt = 1;
				int cache_hit = 0;
				circular_t cache;
				cache.head.next = &cache.head;
				cache.head.item = -1;
				cache.tail = &cache.head;
				cache.num_items = 0;
				while(fgets(buffer, MAX_size, linkbench) != NULL){
						tot_cnt += 1;
						int number = atoi(buffer);
						int hit_value = 0; //if cache hit occurs, its value changes to 1
						node_t *prev = &cache.head;
						node_t *curr = prev->next;
						while(curr != &cache.head){
								if(curr->item == number){
										cache_hit++;
										hit_value = 1;
										if(curr == cache.tail){
												break;
										}
										else{
												prev->next = curr->next;
												free(curr);
												node_t *newNode = (node_t*)malloc(sizeof(node_t));
												newNode->item = number;
												cache.tail->next = newNode;
												newNode->next = &cache.head;
												cache.tail = newNode;
										}
								}
								prev = curr;
								curr = curr->next;
						}
						if(hit_value == 0){
								if(cache.num_items < i){
										node_t *newNode = (node_t*)malloc(sizeof(node_t));
										cache.tail->next = newNode;
										newNode->item = number;
										newNode->next = &cache.head;
										cache.tail = newNode;
										cache.num_items++;
								}
								else{
										node_t *firstNode = cache.head.next;
										cache.head.next = firstNode->next;
										free(firstNode);
										node_t *newNode = (node_t*)malloc(sizeof(node_t));
										newNode->item = number;
										cache.tail->next = newNode;
										newNode->next = &cache.head;
										cache.tail = newNode;
								}
						}
				}
				printf("cache slot = %d, cache hit = %d, hit ratio = %f\n", i, cache_hit, (float)cache_hit / (float)tot_cnt);
				fclose(linkbench);
				cache.head.next = &cache.head;
				cache.tail = &cache.head;
				cache.num_items = 0;
		}
								
		return 0;
}
//반복문을 돈 이후에 fcloce를 하는 방식으로 구현하고, 다시 파일을 여는 방식으로!
//그리고 반복문 안의 마지막에 원형리스트를 초기화하는 코드를 추가
