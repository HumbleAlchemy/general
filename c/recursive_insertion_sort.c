#include<stdio.h>
#include<stdlib.h>

void insert(int a[],int index, int len) {
   
    //find position of element a[index]
    int i = 0,pos = 0,temp_index = index,element = a[index];
    /*for(i = 0; i < index; i++) {*/
    /*    if(a[index] > a[i])     */
    /*        pos++;              */
    /*}                           */
     
    //move all elements before pos to make a hole to place a[index]
    while(temp_index != pos) {
        a[temp_index] = a[temp_index -1];
        temp_index--;
    }
    a[pos] = element;
}

void recursive_insertion_sort(int a[],int last,int len) {
    if( last == -1 ) {
        return;
    } else {
        recursive_insertion_sort(a,last - 1,len);
        insert(a,last,len);
    }
}

int main(int argc, char *argv[])
{
    int a[100];
    int len,i=0;

    scanf("%d",&len);
    for(i = 0; i < len; i++) {
        scanf("%d",&a[i]);
    }
    recursive_insertion_sort(a,len-1,len);
    /* insert(a,4,6); */
    for( i = 0; i < len ; i++ )
    {
        printf("\n %d",a[i]);
    }
    
    return 0;
}

