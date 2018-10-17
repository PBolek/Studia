#include <stdio.h>

int n;
int tab[1000000];

int main()
{
    scanf("%d",&n);
    tab[0]=1, tab[1]=1;
    for(int i=2;i<n;i++)
    {
        for(int j=i+i;j<n;j+=i)
        {
            tab[j]=1;
        }
    }
    for(int i=2;i<n;i++)
    {
        if(tab[i]==0)
        {
            printf("%d ",i);
        }
    }
	return 0;
}
