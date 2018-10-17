//Piotr Bolek Lista 4 Zadanie 1

#include <stdio.h>

//unsigned int = 4 bajty
//unsigned short = 2 bajty

typedef unsigned short TypDaty;

char *Lata[] = { "malpy","koguta","swini","szczura","tygrysa","krolika","smoka","weza","konia","owcy","kozy","psa"};
char *DniTyg[] = {"pon","wto","sro","czw","pio","sob","nie"};
char *Mies[] = {"stycznia","lutego","marca","kwietnia","maja","czerwca","lipica","sierpnia","wrzesnia","pazdziernika","listopada","grudnia"};
int *Dni_Mies[] = {31,28,31,30,31,30,31,31,30,31,30,31};

void WypiszDate(TypDaty data)
{
    int dzien_tyg=0, dzien_mies=0, mies=0, rok=0;
    for(int i=0;i<3;i++)
    {
        if((data&(1<<i))!=0)
        {
            dzien_tyg+=(1<<i);
        }
    }
    for(int i=3;i<8;i++)
    {
        if((data&(1<<i))!=0)
        {
            dzien_mies+=(1<<(i-3));
        }
    }
    for(int i=8;i<12;i++)
    {
        if((data&(1<<i))!=0)
           {
               mies+=(1<<(i-8));
           }
    }
    for(int i=12;i<16;i++)
    {
        if((data&(1<<i))!=0)
        {
            rok+=(1<<(i-12));
        }
    }
    printf("%s, %d %s, rok %s(%d)",DniTyg[dzien_tyg-1],dzien_mies,Mies[mies-1],Lata[rok-1],rok);
}

TypDaty BladDaty(TypDaty data)
{
    int dzien_tyg=0, dzien_mies=0, mies=0, rok=0;
    TypDaty wynik=0;
    wynik=wynik<<16;
    for(int i=0;i<3;i++)
    {
        if((data&(1<<i))!=0)
        {
            dzien_tyg+=(1<<i);
        }
    }
    for(int i=3;i<8;i++)
    {
        if((data&(1<<i))!=0)
        {
            dzien_mies+=(1<<(i-3));
        }
    }
    for(int i=8;i<12;i++)
    {
        if((data&(1<<i))!=0)
           {
               mies+=(1<<(i-8));
           }
    }
    for(int i=12;i<16;i++)
    {
        if((data&(1<<i))!=0)
        {
            rok+=(1<<(i-12));
        }
    }
    if(dzien_tyg>7||dzien_tyg<1)
    {
        for(int i=0;i<3;i++)
        {
            if((data|(1<<i))!=0)
            wynik+=(1<<i);
        }
    }
    if((mies%2!=0&&dzien_mies>31&&mies<=7)||(mies%2==0&&dzien_mies>31&&mies>7)||(mies==2&&dzien_mies>28)||(mies%2==0&&dzien_mies>30)||dzien_mies<1)
    {
        for(int i=3;i<8;i++)
        {
            if((data|(1<<i))!=0)
            {
                wynik+=(1<<i);
            }
        }
    }
    if(mies>12||mies<1)
    {
        for(int i=8;i<12;i++)
        {
            if((data|(1<<i))!=0)
            {
                wynik+=(1<<i);
            }
        }
    }
    if(rok>12||rok<1)
    {
        for(int i=12;i<16;i++)
        {
            if((data|(1<<i))!=0)
            {
                wynik+=(1<<i);
            }
        }
    }
    return wynik;
}

int main()
{
    int blad_dnia_tyg=0,blad_dnia_mies=0,blad_mies=0,blad_roku=0;
    TypDaty x;
    scanf("%hu",&x);
    while(x!=0&&x!=eof(stdin))
    {
        if(BladDaty(x)==0)
        {
            WypiszDate(x);
            printf("\n");
        }
        else
        {
            for(int i=0;i<3;i++)
            {
                if((BladDaty(x)&(1<<i))!=0)
                {
                    blad_dnia_tyg+=(1<<i);
                }
            }
            if(blad_dnia_tyg==7)
            {
                printf("Pole dni tygodnia jest niepoprawne\n");
            }
            for(int i=3;i<8;i++)
            {
                if((BladDaty(x)&(1<<i))!=0)
                {
                    blad_dnia_mies+=(1<<(i-3));
                }
            }
            if(blad_dnia_mies==31)
            {
                printf("Pole dnia miesiaca jest niepoprawne\n");
            }
            for(int i=8;i<12;i++)
            {
                if((BladDaty(x)&(1<<i))!=0)
                {
                    blad_mies+=(1<<(i-8));
                }
            }
            if(blad_mies==15)
            {
                printf("Pole miesiecy jest niepoorawne\n");
            }
            for(int i=12;i<16;i++)
            {
                if((BladDaty(x)&(1<<i))!=0)
                {
                    blad_roku+=(1<<(i-12));
                }
            }
            if(blad_roku==15)
            {
                printf("Pole roku jest niepoprawne\n");
            }
            blad_dnia_mies=0, blad_dnia_tyg=0, blad_mies=0, blad_roku=0;
        }
        scanf("%hu",&x);
    }
    return 0;
}
