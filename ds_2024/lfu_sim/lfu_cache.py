class LPN:
  def __init__(self, value, frequency):
    self.value = value
    self.frequency = frequency
  
class LFU_cache:
  def __init__(self, size):
    self.__cache = []
    self.__uncache = {}
    self.__cacheSize = size
    #cache is a type of minheap and uncache is used to store lpn and frequency by using dictonary. 
		
  def __cacheSearch(self, lpn) -> bool:
    for i in range(0,len(self.__cache)):
      if self.__cache[i].value == lpn:
        self.__cache[i].frequency += 1
        #cache_hit로 인해 바뀐 frequency. Heap을 수정 
        child = 2 * i + 1
        right_child = 2 * i + 2
        while child <= len(self.__cache) - 1:
          if right_child <= len(self.__cache) - 1 and self.__cache[right_child].frequency < self.__cache[child].frequency:
            child = right_child
          if self.__cache[child].frequency < self.__cache[i].frequency:
            self.__cache[child], self.__cache[i] = self.__cache[i], self.__cache[child]
            i = child
            child = 2 * i + 1
            right_child = 2 * i + 2
          else:
            break
        return True
    return False

  def __cacheEnqueue(self, lpn, freq=1):
    i = len(self.__cache)
    newLPN = LPN(lpn, freq)
    self.__cache.append(newLPN)
    parent = (i - 1) // 2
    while(i > 0 and self.__cache[i].frequency < self.__cache[parent].frequency):
      self.__cache[i], self.__cache[parent] = self.__cache[parent], self.__cache[i]
      i = parent
      parent = (i - 1) // 2
  
  def __cacheDequeue(self):
    if self.__cache:
      x = self.__cache[0].value
      y = self.__cache[0].frequency
      self.__cache[0] = self.__cache.pop()
      i = 0
      child = 2 * i + 1
      right_child = 2 * i + 2
      length = len(self.__cache) - 1
      while child <= length:
        if right_child <= length and self.__cache[right_child].frequency < self.__cache[child].frequency:
          child = right_child
        if self.__cache[child].frequency < self.__cache[i].frequency:
          self.__cache[child], self.__cache[i] = self.__cache[i], self.__cache[child]
          i = child
          child = 2 * i + 1
          right_child = 2 * i + 2
        else:
          break
      return (x, y) #(lpn, frequency) this return value when need to store uncache
    else:
      return (None, None)
  
  def __uncacheSearch(self, lpn) -> bool:
    if lpn in self.__uncache:
      freq = self.__uncacheDelete(lpn)
      freq += 1
      if self.__cacheSize == len(self.__cache):
        uncache_lpn, uncache_freq = self.__cacheDequeue()
        self.__uncache[uncache_lpn] = uncache_freq
      self.__cacheEnqueue(lpn, freq)
      return True
    else:
      return False
  
  def __uncacheDelete(self, lpn):
    freq = self.__uncache[lpn]
    del self.__uncache[lpn]
    return freq

  def printAll(self):
    for i in range(0,len(self.__cache)):
      print("cache[",i,"] = ", self.__cache[i].value, ", cache freq : ", self.__cache[i].frequency)
  
  def LFU_simulator(self, lpn) -> bool: #whether cache hit or not
    tf_value = True
    if not self.__cacheSearch(lpn):
      tf_value = False
      if not self.__uncacheSearch(lpn):
        if self.__cacheSize == len(self.__cache):
          uncache_lpn, uncache_freq = self.__cacheDequeue()
          self.__uncache[uncache_lpn] = uncache_freq
        self.__cacheEnqueue(lpn)
    return tf_value
