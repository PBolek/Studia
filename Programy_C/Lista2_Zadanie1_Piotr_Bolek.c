//Piotr Bolek lista 2 zadanie 1

#include <stdio.h>

int NumInput(int baza) // zwraca wczytana wartosc
{
    char kod;
    int value, wynik=0, tab[40],a=0,potega=1, znak=0;
    do
    {
        kod = getchar();
        if(kod == '-')
        {
            znak=1;
        }
        else if(kod>='0'&&kod<='9')
        {
            value = kod - '0';
            tab[a]=value;
            a++;
        }
    }
    while(kod!='.');
    for(int i=a-1; i>=0; i--)
    {
        wynik=wynik+(tab[i]*potega);
        potega*=baza;
    }
    if(znak==1)
    {
        wynik*=(-1);
    }
    return wynik;

}
void NumOutput(int baza, int x) // wypisujemy x w bazie 2..10
{
    int tab[40],a=0, znak=0;
    if(x<0)
    {
        znak=1;
        x*=(-1);
    }
    while(x!=0)
    {
        tab[a]=x%baza;
        x=x/baza;
        a++;
    }
    if(znak == 1)
    {
        putchar('-');
    }
    for(int i=a-1; i>=0; i--)
    {
        char c=tab[i]+'0';
        putchar(c);
    }
}

int main()
{
    int x;
    do
    {
        x=NumInput(10); // wczytaj liczbe o bazie 10
        NumOutput(10, x); // wypisz x o bazie 10
        putchar(' ');
        NumOutput(2, x); // wypisz x w bazie 2;
        putchar('\n');
    }
    while(x!=0);
    return 0;
}
