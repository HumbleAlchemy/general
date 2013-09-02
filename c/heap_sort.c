#include<stdio.h>
#define ARR_LEN(x) (sizeof(x)/sizeof(x[0]))
//structure of array for heap
struct heap_array {
	int keys[100];
	int length;
	int heap_size;
};

typedef struct heap_array heap_array;

//parent
int parent(heap_array A,int i){
	int p = i/2;
	if(p >= 1 && p < A.heap_size)
		return p;
	else
		return -1;
}

//left
int left(heap_array A,int i){
	int l = 2*i + 1;
	if(l >=0 && l < A.heap_size)
		return l;
	else
		return -1;
}

//right
int right(heap_array A,int i){
	int r = 2*i + 2;
	if(r >=0 && r < A.heap_size)
		return r;
	else
		return -1;
}

//swap
void swap(int arr[], int i , int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//max_heapify
void max_heapify(heap_array *A, int i) {
	int l = left(*A,i);
	int r = right(*A,i);
	int largest = i;

//	printf("    l : %d\n",l);
//	printf("    r : %d\n",r);

	if(l != -1) {
		if(l <= A->heap_size && A->keys[l] < A->keys[i]) {
			largest = l;
//			printf("largest: %d \n",largest);
		} else {
			largest = i;
//			printf("largest: %d \n",largest);
		}
	}
	if(r != -1){
		if(r <= A->heap_size && A->keys[r] < A->keys[largest]) {
			largest = r;
		}
//		printf("largest: %d \n",largest); 
	}
	if(largest != i) {
//		printf("before swap : %d %d\n",A->keys[i],A->keys[largest]);
		swap(A->keys,i,largest);
//		printf("after swap : %d %d\n",A->keys[i],A->keys[largest]);
		max_heapify(A,largest);
	}	
}
//build max heap
void build_max_heap(heap_array *A) {
	int i =0;
	A->heap_size = A->length;
	for(i = A->length/2 ; i >=0 ; i--)
		max_heapify(A,i);
}
void display(heap_array A) {
	int i =0;
	printf("[");
	for(i =0 ; i<A.length; i++) 
		if(i < A.length-1) 
            printf("%3d,",A.keys[i]);
        else
            printf("%3d]\n",A.keys[i]);
	
}

//heapsort
void heapsort(heap_array *A) {
	int i =0;
	build_max_heap(A);
	for(i = A->length-1; i >=1; i--) {
		swap(A->keys,0,i);
		A->heap_size = A->heap_size -1 ;
		max_heapify(A,0);
	}
}

//priority queue
int heap_extract(heap_array *A) {
    int ext;
    if (A->heap_size < 0)
        printf("heap underflow");
    ext = A->keys[0];
    A->keys[0] = A->keys[A->heap_size-1];
    A->heap_size = A->heap_size - 1;
    max_heapify(A,0);
    return ext;
}

int main(int argc, const char *argv[])
{
	heap_array A;
	int arr[] = {4,1,3,2,16,9,10,14,8,7};
	int i=0,s1 =2,s2 = 4;

	printf("array size: %d\n",ARR_LEN(arr));
	
	A.heap_size = ARR_LEN(arr);
	A.length = ARR_LEN(arr);
	for(i=0;i < ARR_LEN(arr); i++)
		A.keys[i] = arr[i];
	
	for(i; i < 100 ; i++)
		A.keys[i] = -1;

	display(A); //display unsorted list
	heapsort(&A);
	display(A);
	
    return 0;
}
