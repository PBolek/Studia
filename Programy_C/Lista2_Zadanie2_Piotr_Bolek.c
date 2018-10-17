//Piotr Bolek Kurs ANSI C lista 2 zadanie 2

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
        else if(kod>='A'&&kod<='F')
        {
            tab[a]=kod;
            a++;
        }
    }
    while(kod!='.');
    for(int i=a-1; i>=0; i--)
    {
        if(baza==16)
        {
            if(tab[i]=='A')
            {
                wynik=wynik+(10*potega);
                potega*=baza;
            }
            else if(tab[i]=='B')
            {
                wynik=wynik+(11*potega);
                potega*=baza;
            }
            else if(tab[i]=='C')
            {
                wynik=wynik+(12*potega);
                potega*=baza;
            }
            else if(tab[i]=='D')
            {
                wynik=wynik+(13*potega);
                potega*=baza;
            }
            else if(tab[i]=='E')
            {
                wynik=wynik+(14*potega);
                potega*=baza;
            }
            else if(tab[i]=='F')
            {
                wynik=wynik+(15*potega);
                potega*=baza;
            }
            else
            {
                wynik=wynik+(tab[i]*potega);
                potega*=baza;
            }
        }
        else
        {
            wynik=wynik+(tab[i]*potega);
            potega*=baza;
        }
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
        if(baza==16)
        {
            if(tab[i]==10)
            {
                putchar(65); //wypisz A
            }
            else if(tab[i]==11)
            {
                putchar(66); // wypisz B
            }
            else if(tab[i]==12)
            {
                putchar(67); // wypisz C
            }
            else if(tab[i]==13)
            {
                putchar(68); // wypisz D
            }
            else if(tab[i]==14)
            {
                putchar(69); //wypisz E
            }
            else if(tab[i]==15)
            {
                putchar(70); //wypisz F
            }
            else
            {
                char c=tab[i]+'0';
                putchar(c);
            }
        }
        else
        {
            char c=tab[i]+'0';
            putchar(c);
        }

    }
}

int main()
{
    int x,y,wynik_dzialania;
    char znak;
    do
    {
        x=NumInput(16);
        znak=getchar();
        if(znak=='+')
        {
            y=NumInput(16);
            wynik_dzialania = x+y;
            NumOutput(10,wynik_dzialania);
            putchar('\n');
        }
        else if(znak=='-')
        {
            y=NumInput(16);
            wynik_dzialania = x-y;
            NumOutput(10,wynik_dzialania);
            putchar('\n');
        }
        else if(znak=='*')
        {
            y=NumInput(16);
            wynik_dzialania = x*y;
            NumOutput(10,wynik_dzialania);
            putchar('\n');
        }
        else if(znak=='/')
        {
            y=NumInput(16);
            wynik_dzialania = x/y;
            NumOutput(10,wynik_dzialania);
            putchar('\n');
        }
        else if(znak=='!')
        {
            wynik_dzialania=1;
            for(int i=1;i<=x;i++)
            {
                wynik_dzialania*=i;
            }
            NumOutput(10,wynik_dzialania);
            putchar('\n');

        }
    }
    while(x!=0);
    return 0;
}
