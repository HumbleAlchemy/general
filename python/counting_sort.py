""" progrm to implement counting sort """

import random

def counting_sort(num_list,max_range):
	aux_list = [0 for i in xrange(0,max_range+1)]
	print num_list
	for i in num_list:
		aux_list[num_list[i]] = aux_list[num_list[i]] + 1
	
	print aux_list
	for i in xrange(1,len(aux_list)):
		aux_list[i] = aux_list[i] + aux_list[i-1]
		
	sorted_list = [0 for i in xrange(0,101)]
	for i in xrange(len(num_list)-1,-1,-1):
		sorted_list[aux_list[num_list[i]]] = num_list[i]
		aux_list[i] = aux_list[i] - 1
	
	return sorted_list


def main():
	num_list = []
	for i in xrange(0,101):
		num_list.append(random.randint(0,100))
	
	print counting_sort(num_list,100)

if __name__ == "__main__":
	main()
