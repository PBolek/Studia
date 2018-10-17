//Piotr Bolek Zadanie 2 Lista 5

#include <stdio.h>
#include <stdlib.h>

void SpiralaWiersz(int n, int k)
{
    if(n==1)
    {
        printf("%4d", n);
    }
    else if(n%2==0)
    {
        if(k==n)
        {
            for(int i=0;i<n;i++)
            {
                printf("%4d",n*n-2*n+2+i);
            }
        }
        else
        {
            SpiralaWiersz(n-1,k);
            printf("%4d",n*n-(k-1));
        }
    }
    else
    {
        if(k==1)
        {
            for(int i=0;i<n;i++)
            {
                printf("%4d", n*n-n+1-i);
            }
        }
        else
        {
            printf("%4d", n*n-n+k);
            SpiralaWiersz(n-1,k-1);
        }
    }
}

int main(int argc, char*argv[])
{
    int n;
    if(argc==1)
    {
        n=17;
    }
    else
    {
        n=atoi(argv[1]);
    }
    for(int i=1;i<=n;i++)
    {
        SpiralaWiersz(n,i);
        if(i!=n)
        {
            printf("\n");
        }
    }
    return 0;
}
