#include<stdio.h>

#define max(X,Y) ((X > Y) ? X : Y)


int memoized_rod_cut(int p[], int n,int r[]) {
    int q = -1,i = 0,tmax=0;
    if(r[n] >= 0)
        return r[n];
    if(n == 0)
        return q = 0;
    else {
        q = -1;
        for( i=1 ; i <= n ; i++ )
        {
            tmax = p[i] + memoized_rod_cut(p,n-i,r);
            q = max(q,tmax);
            //q = max(q,p[i]+rod_cut(p,n-i));
        }
    }
    r[n] = q;
    return q;
}

int init_memoized_rod_cutting(int p[], int n) {
    int r[100],i=0;
    for( i=0 ; i<100 ; i++ )
    {
        r[i] = -1;
    }
    return memoized_rod_cut(p,n,r);
}

//test main
int main(int argc, char *argv[])
{
    int p[] = {0,1,5,8,9,10,17,17,20,24,30};
    
    int opt_revenue = 0;
    int n = 1;
    if(sscanf(argv[1],"%i",&n) != 1)
        printf("error - not an integer");
    opt_revenue = init_memoized_rod_cutting(p,n);
    printf("\nr(n): %d\n\n",opt_revenue);
    return 0;
}
