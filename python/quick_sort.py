"""
this is program to implement quick sort
"""
import random

def qsort(sort_list,left,right):
    """implementation of quicksort """
    print sort_list
    if left < right:
        pivot_index = select_pivot_index(sort_list,left,right)
        new_pivot_index = partition(sort_list,left,right,pivot_index)
        qsort(sort_list,left,new_pivot_index-1)
        qsort(sort_list,new_pivot_index+1,right)


def select_pivot_index(sort_list,left,right):

    """returns a pivot index"""
    return left

def partition(sort_list,left,right,pivot_index):
    """ to find the new position of pivot """
    sort_list[left], sort_list[pivot_index] = sort_list[pivot_index], sort_list[left]
    i = left + 1
    for j in xrange(left+1,right+1):
        if sort_list[j] < sort_list[pivot_index]:
            sort_list[i],sort_list[j] = sort_list[j],sort_list[i]
            i = i + 1
    sort_list[left] , sort_list[i-1] = sort_list[i-1] , sort_list[left]
    return i-1

if __name__ == "__main__":
    l = range(1,15)
    random.shuffle(l)
    l.reverse()
    #i = partition(l,0,len(l)-1,0)
    qsort(l,0,len(l)-1)
    print l
