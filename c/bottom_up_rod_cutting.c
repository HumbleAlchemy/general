#include<stdio.h>

#define max(X,Y) ((X > Y) ? X : Y)

int bottom_up_rod_cut(int p[], int n) {
    int q = -1,i = 0,j=0,tmax=0;
    int r[100];
    for( i=0 ; i<100 ; i++ )
    {
        r[i] = 0;
    }
    
    for( j=0 ; j <= n ; j++ )
    {
        q = -1;
        for( i=0 ; i<=j ; i++ )
        {
            tmax = p[i] + r[j-i];
            q = max(q,tmax);
            //q = max(q,p[i]+rod_cut(p,n-i));
        }
        r[j] = q;
    }
    return r[n];
}

//test main
int main(int argc, char *argv[])
{
    int p[] = {0,1,5,8,9,10,17,17,20,24,30};
    int opt_revenue = 0;
    int n = 1;
    if(sscanf(argv[1],"%i",&n) != 1)
        printf("error - not an integer");
    opt_revenue =bottom_up_rod_cut(p,n);
    printf("\nr(n): %d\n\n",opt_revenue);
    return 0;
}
