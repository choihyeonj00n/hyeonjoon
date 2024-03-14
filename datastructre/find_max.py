def find_max_reculsive(n, list):
		if n == 9:
			return list[9]
		else :
			if list[n] > find_max_reculsive(n+1, list):
					return list[n]
			else:
			  		return find_max_reculsive(n+1, list)

def find_max_iterative(list):
		max = list[0]
		for i in range(1,10):
			if(max < list[i]):
					max = list[i]
		return max


'''execution'''
list = []
for i in range(10):
		x = int(input())
		list.append(x)

a = find_max_reculsive(0, list);
b = find_max_iterative(list);
print("find_max_reculsive : ", a)
print("find_max_iterative : ", b)
