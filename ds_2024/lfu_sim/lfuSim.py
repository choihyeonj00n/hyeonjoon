from lfu_cache import * 

def lfu_sim(cache_slots):
  cache_hit = 0
  tot_cnt = 0
  lfu_cache = LFU_cache(cache_slots)

  data_file = open("linkbench.trc")


  for line in data_file.readlines():
    lpn = line.split()[0]

    tot_cnt += 1
    if lfu_cache.LFU_simulator(lpn):
      cache_hit += 1

  print("cache_slot = ", cache_slots, "cache_hit = ", cache_hit, "hit ratio = ", cache_hit / tot_cnt)

if __name__ == "__main__":
  for cache_slots in range(100, 1000, 100):
    lfu_sim(cache_slots)
