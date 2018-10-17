//Piotr Bolek Lista 4 Zadanie 2

#include <stdio.h>

//unsigned int = 4 bajty
//unsigned short = 2 bajty

typedef unsigned short TypDaty;

char *Lata[] = { "malpy","koguta","swini","szczura","tygrysa","krolika","smoka","weza","konia","owcy","kozy","psa"};
char *DniTyg[] = {"pon","wto","sro","czw","pio","sob","nie"};
char *Mies[] = {"stycznia","lutego","marca","kwietnia","maja","czerwca","lipica","sierpnia","wrzesnia","pazdziernika","listopada","grudnia"};
int Dni_Mies[] = {31,28,31,30,31,30,31,31,30,31,30,31};

void WypiszDate(TypDaty data)
{
    int dzien_tyg=0, dzien_mies=0, mies=0, rok=0;
    for(int i=0; i<3; i++)
    {
        if((data&(1<<i))!=0)
            dzien_tyg+=(1<<i);
    }
    for(int i=3; i<8; i++)
    {
        if((data&(1<<i))!=0)
            dzien_mies+=(1<<(i-3));
    }
    for(int i=8; i<12; i++)
    {
        if((data&(1<<i))!=0)
            mies+=(1<<(i-8));
    }
    for(int i=12; i<16; i++)
    {
        if((data&(1<<i))!=0)
            rok+=(1<<(i-12));
    }
    printf("%s, %d %s, rok %s(%d)",DniTyg[dzien_tyg-1],dzien_mies,Mies[mies-1],Lata[rok-1],rok);
}

TypDaty BladDaty(TypDaty data)
{
    int dzien_tyg=0, dzien_mies=0, mies=0, rok=0;
    TypDaty wynik=0;
    for(int i=0; i<3; i++)
    {
        if((data&(1<<i))!=0)
            dzien_tyg+=(1<<i);
    }
    for(int i=3; i<8; i++)
    {
        if((data&(1<<i))!=0)
            dzien_mies+=(1<<(i-3));
    }
    for(int i=8; i<12; i++)
    {
        if((data&(1<<i))!=0)
            mies+=(1<<(i-8));
    }
    for(int i=12; i<16; i++)
    {
        if((data&(1<<i))!=0)
            rok+=(1<<(i-12));
    }
    if(dzien_tyg>7||dzien_tyg<1)
    {
        for(int i=0; i<3; i++)
        {
            if((data|(1<<i))!=0)
                wynik+=(1<<i);
        }
    }
    if(dzien_mies==0||dzien_mies>Dni_Mies[mies])
    {
        for(int i=3; i<8; i++)
        {
            if((data|(1<<i))!=0)
                wynik+=(1<<i);
        }
    }
    if(mies>12||mies<1)
    {
        for(int i=8; i<12; i++)
        {
            if((data|(1<<i))!=0)
                wynik+=(1<<i);
        }
    }
    if(rok>12||rok<1)
    {
        for(int i=12; i<16; i++)
        {
            if((data|(1<<i))!=0)
                wynik+=(1<<i);
        }
    }
    return wynik;
}

int Odleglosc(TypDaty d1, TypDaty d2)
{
    int dzien_tyg=0,dzien_mies=0,mies=0,rok=0,dzien_tyg2=0,dzien_mies2=0,mies2=0,rok2=0,dni1=0,dni2=0;
    for(int i=0; i<3; i++)
    {
        if((d1&(1<<i))!=0)
            dzien_tyg+=(1<<i);
    }
    for(int i=3; i<8; i++)
    {
        if((d1&(1<<i))!=0)
            dzien_mies+=(1<<(i-3));
    }
    for(int i=8; i<12; i++)
    {
        if((d1&(1<<i))!=0)
            mies+=(1<<(i-8));
    }
    for(int i=12; i<16; i++)
    {
        if((d1&(1<<i))!=0)
            rok+=(1<<(i-12));
    }
    for(int i=0; i<3; i++)
    {
        if((d2&(1<<i))!=0)
            dzien_tyg2+=(1<<i);
    }
    for(int i=3; i<8; i++)
    {
        if((d2&(1<<i))!=0)
            dzien_mies2+=(1<<(i-3));
    }
    for(int i=8; i<12; i++)
    {
        if((d2&(1<<i))!=0)
            mies2+=(1<<(i-8));
    }
    for(int i=12; i<16; i++)
    {
        if((d2&(1<<i))!=0)
            rok2+=(1<<(i-12));
    }
    if(rok>1)
    {
        dni1+=dzien_mies;
        if(mies>1)
        {
            for(int i=0; i<mies-1; i++)
                dni1+=Dni_Mies[i];
        }
        dni1+=((rok-1)*365);
    }
    else
    {
        dni1+=dzien_mies;
        if(mies>1)
        {
            for(int i=0; i<mies-1; i++)
                dni1+=Dni_Mies[i];
        }
    }
    if(rok2>1)
    {
        dni2+=dzien_mies2;
        if(mies2>1)
        {
            for(int i=0; i<mies2-1; i++)
                dni2+=Dni_Mies[i];
        }
        dni2+=((rok2-1)*365);
    }
    else
    {
        dni2+=dzien_mies2;
        if(mies2>1)
        {
            for(int i=0; i<mies2-1; i++)
                dni2+=Dni_Mies[i];
        }
    }
    int roznica=0;
    if(dni1<dni2)
        roznica=(dni2-dni1);
    else
        roznica=(dni1-dni2);
    return roznica;
}

TypDaty ZrobDate(short dt, short d, short m, short rok)
{
    TypDaty data=0;
    data=(data|dt);
    data=(data|(d<<3));
    data=(data|(m<<8));
    data=(data|(rok<<12));
    return data;
}

int main()
{
    int blad_dnia_tyg=0,blad_dnia_mies=0,blad_mies=0,blad_roku=0, blad_dnia_tyg2=0,blad_dnia_mies2=0,blad_mies2=0,blad_roku2=0;
    short dt, d, m, rok, dt2, d2, m2, rok2;
    TypDaty data1, data2, bdata1, bdata2;
    while(1)
    {
        scanf("%hu",&dt);
        if(dt==0)
            break;
        scanf("%hu%hu%hu",&d,&m,&rok);
        scanf("%hu",&dt2);
        if(dt2==0)
            break;
        scanf("%hu%hu%hu",&d2,&m2,&rok2);
        data1=ZrobDate(dt,d,m,rok);
        data2=ZrobDate(dt2,d2,m2,rok2);
        bdata1=BladDaty(data1);
        bdata2=BladDaty(data2);
        if(bdata1==0&&bdata2==0)
        {
            printf("%d ",ZrobDate(dt,d,m,rok));
            WypiszDate(data1);
            printf("\n%d ",ZrobDate(dt2,d2,m2,rok2));
            WypiszDate(data2);
            printf("\nOdleglosc miedzy datami: %d\n",Odleglosc(data1,data2));
        }
        else
        {
            if(bdata1!=0)
            {
                printf("Pierwsza data:\n");
                for(int i=0; i<3; i++)
                {
                    if((bdata1&(1<<i))!=0)
                        blad_dnia_tyg+=(1<<i);
                }
                if(blad_dnia_tyg==7)
                    printf("Pole dni tygodnia jest niepoprawne\n");
                for(int i=3; i<8; i++)
                {
                    if((bdata1&(1<<i))!=0)
                        blad_dnia_mies+=(1<<(i-3));
                }
                if(blad_dnia_mies==31)
                    printf("Pole dnia miesiaca jest niepoprawne\n");
                for(int i=8; i<12; i++)
                {
                    if((bdata1&(1<<i))!=0)
                        blad_mies+=(1<<(i-8));
                }
                if(blad_mies==15)
                    printf("Pole miesiecy jest niepoorawne\n");
                for(int i=12; i<16; i++)
                {
                    if((bdata1&(1<<i))!=0)
                        blad_roku+=(1<<(i-12));
                }
                if(blad_roku==15)
                    printf("Pole roku jest niepoprawne\n");
            }
            if(bdata2!=0)
            {
                printf("Druga data:\n");
                for(int i=0; i<3; i++)
                {
                    if((bdata2&(1<<i))!=0)
                        blad_dnia_tyg2+=(1<<i);
                }
                if(blad_dnia_tyg2==7)
                    printf("Pole dni tygodnia jest niepoprawne\n");
                for(int i=3; i<8; i++)
                {
                    if((bdata2&(1<<i))!=0)
                        blad_dnia_mies2+=(1<<(i-3));
                }
                if(blad_dnia_mies2==31)
                    printf("Pole dnia miesiaca jest niepoprawne\n");
                for(int i=8; i<12; i++)
                {
                    if((bdata2&(1<<i))!=0)
                        blad_mies2+=(1<<(i-8));
                }
                if(blad_mies2==15)
                    printf("Pole miesiecy jest niepoorawne\n");
                for(int i=12; i<16; i++)
                {
                    if((bdata2&(1<<i))!=0)
                        blad_roku2+=(1<<(i-12));
                }
                if(blad_roku2==15)
                    printf("Pole roku jest niepoprawne\n");
            }
            blad_dnia_mies=0, blad_dnia_tyg=0, blad_mies=0, blad_roku=0;
            blad_dnia_mies2=0, blad_dnia_tyg2=0, blad_mies2=0, blad_roku2=0;
        }
    }
    return 0;
}
