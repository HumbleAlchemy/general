#include<stdio.h>

#define max(X,Y) ((X > Y) ? X : Y)

int bottom_up_rod_cut(int p[], int s[], int n) {
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
            if(q < (p[i] + r[j-i])) {
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return r[n];
}

//test main
int main(int argc, char *argv[])
{
    int p[] = {0,1,5,8,9,10,17,17,20,24,30};
    int s[100];
    int opt_revenue = 0;
    int n = 1,i=0;

    for( i =0 ; i <100 ; i++ )
        s[i] = 0;
    
    if(sscanf(argv[1],"%i",&n) != 1)
        printf("error - not an integer");
    opt_revenue =bottom_up_rod_cut(p,s,n);
    printf("\nr(n): %d\n",opt_revenue);

    while(n > 0)
    {
        printf("%d\n",s[n]);
        n = n - s[n];
    }
    
    return 0;
}
