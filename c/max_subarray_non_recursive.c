#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* represents negative infinity */
#define MIN_INF (-(int)pow(2,32)-1)

/* it performs the maximum subarray search in O(n) time  */
int kadane_algorithm(int a[],int length, int *from, int *to) {
   int i =0;
   int begin = 0,begin_temp = 0, end = 0;
   int max_ending_here = MIN_INF ,max_so_far = MIN_INF;
   for( i ; i <length ; i++ )
   {
       if( max_ending_here < 0 )
       {
           max_ending_here = a[i];
           begin_temp = i;
       }
       else {
            max_ending_here += a[i];
       }

       if( max_ending_here >= max_so_far )
       {
           max_so_far = max_ending_here;
           begin = begin_temp;
           end = i;
       }

   }

    *from = begin;
    *to = end;
    return max_so_far;
   
}

int main(int argc, char *argv[])
{
    int *a,length;
    int i = 0,sum,from,to;
    scanf("%d",&length);
    a = malloc(sizeof(int)*length);
    for( i ; i < length ; i++ )
    {
        scanf("\n%d",&a[i]);
    }
    from = 0;
    to = length -1;
    sum = kadane_algorithm(a,length,&from,&to);
    /* printf("\n %d",MIN_INF <= -1 ? MIN_INF : -1); */
    printf("\n%d %d %d",sum,from,to); 
}
