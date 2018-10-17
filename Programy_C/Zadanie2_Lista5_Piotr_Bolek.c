//Piotr Bolek Zadanie 2 Lista 5

#include <stdio.h>
#include <stdlib.h>

FILE *zw;

int czy_pierwsza(int n)
{
    int suma=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            suma++;
        }
    }
    if(suma>2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void SpiralaWiersz(int n, int k)
{
    if(n==1)
    {
        fprintf(zw,"0 0 255 ");
    }
    else if(n%2==0)
    {
        if(k==n)
        {
            for(int i=0;i<n;i++)
            {
                if(czy_pierwsza(n*n-2*n+2+i)==1)
                {
                    fprintf(zw,"255 0 0 ");
                }
                else
                {
                    fprintf(zw,"0 0 255 ");
                }
            }
        }
        else
        {
            SpiralaWiersz(n-1,k);
            if(czy_pierwsza(n*n-(k-1))==1)
            {
                fprintf(zw,"255 0 0 ");
            }
            else
            {
                fprintf(zw,"0 0 255 ");
            }
        }
    }
    else
    {
        if(k==1)
        {
            for(int i=0;i<n;i++)
            {
                if(czy_pierwsza(n*n-n+1-i)==1)
                {
                    fprintf(zw,"255 0 0 ");
                }
                else
                {
                    fprintf(zw,"0 0 255 ");
                }
            }
        }
        else
        {
            if(czy_pierwsza(n*n-n+k)==1)
            {
                fprintf(zw,"255 0 0 ");
            }
            else
            {
                fprintf(zw,"0 0 255 ");
            }
            SpiralaWiersz(n-1,k-1);
        }
    }
}

int main(int argc, char*argv[])
{
    char *nazwa=argv[2];
    int n;
    zw=fopen(nazwa,"a");
    if(argc==1)
    {
        n=17;
    }
    else
    {
        n=atoi(argv[1]);
    }
    fprintf(zw,"P3\n%d %d\n255\n",n,n);
    for(int i=1;i<=n;i++)
    {
        SpiralaWiersz(n,i);
        if(i!=n)
        {
            fprintf(zw,"\n");
        }
    }
    fclose(zw);
    return 0;
}
