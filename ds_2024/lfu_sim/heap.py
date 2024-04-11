class Heap:
		def __init__(self, list):
				if list == None:
						self.__A = []
				else :
						self.__A = list

		def insert(self, x):
				self.__A.append(x)
				self.__percolateUP(len(self.__A)-1)

		def __percolateUP(self, i:int):
				parent = (i - 1) // 2
				if i > 0 and self.__A[i] > self.__A[parent]:
						self.__A[i], self.__A[parent] = self.__A[parent], self.__A[i]
						self.__percolateUP(parent)

		def deleteMax(self):
				if(not self.isEmpty()):
						max = self.__A[0]
						self.__A[0] = self.__A.pop() #delete last leaf node and insert to root node and relocate heap
						self.__percolateDown(0)
						return max
				else :
						return None

		def __percolateDown(self, i:int):
				left_child = 2 * i + 1
				right_child = 2 * i + 2
				if left_child <= len(self.__A) - 1:
						if right_child <= len(self.__A) - 1 and self.__A[left_child] < self.__A[right_child]:
								left_child = right_child
						if self.__A[i] < self.__A[left_child]:
								self.__A[i], self.__A[left_child] = self.__A[left_child], self.__A[i]
								self.__percolateDown(left_child)

		def max(self):
				return self.__A[0]

		def buildHeap(self):
				for i in range((len(self.__A) - 2) // 2, -1, -1):
						self.__percolateDown(i)

		def isEmpty(self) -> bool:
				return len(self.__A) == 0

		def clear(self):
				self.__A = []

		def size(self) -> int:
				return len(self.__A)

		def heapPrint(self):
				print("=====================\n")
				n_start = 0
				n_end = 1
				count = 1
				while n_start < len(self.__A):
						count += 1
						for i in range(n_start, min(n_end, len(self.__A))):  
								print(self.__A[i], end=" ")
						print("\n")
						n_start = n_end
						n_end = 2 ** count - 1
