#include <stdio.h>

int n, suma=0,a=0, tab[10000];

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=i;j++)
        {
            if(i%j==0)
            {
                suma++;
            }
        }
        if(suma==1)
        {
            tab[a]=i;
            a++;
        }
        suma=0;
    }
    for(int i=0;i<a;i++)
    {
        printf("%d ",tab[i]);
    }

	return 0;
}
