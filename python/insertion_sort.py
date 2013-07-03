-------------------------------------------------------------------------------
import unittest

class Comparers:

    def integer_compare_ascending(self,x , y):
        ''' function to implement custom comparison type '''
        return True if x < y else False

class SortingAlgorithms:
    def insertion_sort(self,compare,list=[]):

        """
        doctest for sorting alogrithm

        >>> insertion_sort(compare,[1,4,7,2,0])
        [0, 1, 2, 4, 7]
        """
        '''function to implement insertion sort '''
        for i in xrange(0,len(list)):
            element_in_hand = list[i]
            temp_pos = i
            while temp_pos > 0 and compare(element_in_hand,list[temp_pos-1]):
                list[temp_pos] = list[temp_pos - 1]
                temp_pos = temp_pos - 1
            list[temp_pos] = element_in_hand
        return list


class TestSortingAlgorithms(unittest.TestCase):
    def test_insertion_sort(self):
        sa = SortingAlgorithms()
        input_list = [1,0,9,2,5,3]
        output_list = [0,1,2,3,5,9]
        compare = Comparers()
        self.assertEqual(output_list,sa.insertion_sort(compare.integer_compare_ascending,input_list))

##def main():
##    list = [
##        8,4,1,3,
##        6,2,9,1
##        ]
##    list = insertion_sort(compare,list)
##    print(list)

if __name__ == '__main__':
    unittest.main()
