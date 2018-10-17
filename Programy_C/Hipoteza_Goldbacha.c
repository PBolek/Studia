#include <stdio.h>

int n,suma=0,a=0,tab[100000007],pq=0;

int main()
{
    scanf("%d",&n);
    if(n%2!=0||n<=2)
    {
        printf("NIEPOPRAWNA LICZBA");
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                suma++;
            }
        }
        if(suma==2)
        {
            tab[a]=i;
            a++;
        }
        suma=0;
    }
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=a;j++)
        {
            if(tab[i]+tab[j]==n&&tab[i]<=tab[j])
            {
                printf("%d %d\n",tab[i], tab[j]);
                pq++;
            }
        }
    }
    printf("%d",pq);
	return 0;
}
