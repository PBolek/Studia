#include <stdio.h>

int baza, liczba, a,b,wynik;
int tab[100000];

int main()
{
    scanf("%d",&baza);
    scanf("%d",&liczba);
    while(liczba!=0)
    {
        liczba=liczba/baza;
        tab[a]=liczba%baza;
        a++;
    }
    for(int i=a;i>0;i--)
    {
        if(b==0)
        {
            wynik++;
        }
        for(int j=0;j<b;j++)
        {
            wynik=tab[j]*baza;
        }
        b++;
    }
    printf("%d ",wynik);
    for(int i=a-1;i>=0;i--)
    {
        printf("%d", tab[i]);
    }
    return 0;
}
