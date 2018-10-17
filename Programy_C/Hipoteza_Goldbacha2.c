#include <stdio.h>

int n, tab[10000007], tabi[10000007], a=0,suma=0;

int main()
{
    scanf("%d",&n);
    if(n%2!=0||n<=2)
    {
        printf("NIEPOPRAWNA LICZBA");
        return 0;
    }
    tab[0]=1, tab[1]=1;
    for(int i=2; i<n; i++)
    {
        if(tab[i] == 0)
            for(int j=i+i; j<=n; j+=i)
            {
                tab[j]=1;
            }
    }
    for(int i=2;i<n;i++)
    {
        if(tab[i]==0&&tab[n-i]==0&&n-i>=i)
        {
            suma++;
        }
    }
    printf("%d",suma);

    return 0;
}
