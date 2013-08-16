#include<stdio.h>

#define max(X,Y) ((X > Y) ? X : Y)

int rod_cut(int p[], int n) {
    int q = -1,i = 0,tmax=0;
    if(n == 0)
        return 0;
    for( i=1 ; i <= n ; i++ )
    {
        tmax = p[i] + rod_cut(p,n-i);
        q = max(q,tmax);
        //q = max(q,p[i]+rod_cut(p,n-i));
    }

    return q;
}

//test main
int main(int argc, char *argv[])
{
    int p[] = {0,1,5,8,9,10,17,17,20,24,30};
    int opt_revenue = 0;
    int n = 1;
    if(sscanf(argv[1],"%i",&n) != 1)
        printf("error - not an integer");
    opt_revenue = rod_cut(p,n);
    printf("\nr(n): %d\n\n",opt_revenue);
    return 0;
}
