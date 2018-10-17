#include <stdio.h>

int tab[513],koniec[513],czas_gry,min_koniec=10e8,max_poczatek=0,max_czas=0,g1,g2,g3,g4,wynik=0,koniecc,pocz,wynik1=0,wynik2=0,wynik3=0,wynik4=0,wynik5=0;
int miesiac, dzien_miesiaca, godzina, minuty, sekundy;

int main()
{
    int liczba_graczy;
    scanf("%d",&liczba_graczy);
    for(int i=0; i<liczba_graczy; i++)
    {
        scanf("%d%d%d%d%d",&miesiac,&dzien_miesiaca,&godzina,&minuty,&sekundy);
        tab[i]=(tab[i]|(sekundy));
        tab[i]=(tab[i]|(minuty<<6));
        tab[i]=(tab[i]|(godzina<<12));
        tab[i]=(tab[i]|(dzien_miesiaca<<17));
        tab[i]=(tab[i]|(miesiac<<22));
        scanf("%d%d%d%d%d",&miesiac,&dzien_miesiaca,&godzina,&minuty,&sekundy);
        koniec[i]=(koniec[i]|(sekundy));
        koniec[i]=(koniec[i]|(minuty<<6));
        koniec[i]=(koniec[i]|(godzina<<12));
        koniec[i]=(koniec[i]|(dzien_miesiaca<<17));
        koniec[i]=(koniec[i]|(miesiac<<22));
    }
    for(int i=0; i<liczba_graczy; i++)
    {
        for(int j=i+1; j<liczba_graczy; j++)
        {
            min_koniec=koniec[i];
            max_poczatek=tab[i];
            if(min_koniec>koniec[j])
            {
                min_koniec=koniec[j];
            }
            if(max_poczatek<tab[j])
            {
                max_poczatek=tab[j];
            }
            if(min_koniec-max_poczatek<max_czas)
            {
                continue;
            }
            for(int z=j+1; z<liczba_graczy; z++)
            {
                min_koniec=koniec[i];
                max_poczatek=tab[i];
                if(min_koniec>koniec[j])
                {
                    min_koniec=koniec[j];
                }
                if(max_poczatek<tab[j])
                {
                    max_poczatek=tab[j];
                }
                if(min_koniec>koniec[z])
                {
                    min_koniec=koniec[z];
                }
                if(max_poczatek<tab[z])
                {
                    max_poczatek=tab[z];
                }
                if(min_koniec-max_poczatek<max_czas)
                {
                    continue;
                }
                for(int k=z+1; k<liczba_graczy; k++)
                {
                    min_koniec=koniec[i];
                    max_poczatek=tab[i];
                    if(min_koniec>koniec[j])
                    {
                        min_koniec=koniec[j];
                    }
                    if(max_poczatek<tab[j])
                    {
                        max_poczatek=tab[j];
                    }
                    if(min_koniec>koniec[z])
                    {
                        min_koniec=koniec[z];
                    }
                    if(max_poczatek<tab[z])
                    {
                        max_poczatek=tab[z];
                    }
                    if(min_koniec>koniec[k])
                    {
                        min_koniec=koniec[k];
                    }
                    if(max_poczatek<tab[k])
                    {
                        max_poczatek=tab[k];
                    }
                    if(min_koniec-max_poczatek<max_czas)
                    {
                        continue;
                    }
                    if(min_koniec>max_poczatek)
                    {
                        czas_gry=min_koniec-max_poczatek;
                        if(max_czas<czas_gry)
                        {
                            max_czas=czas_gry;
                            g1=k,g2=z,g3=j,g4=i;
                            koniecc=min_koniec;
                            pocz=max_poczatek;
                        }
                    }
                }
            }
        }
    }
    if(max_czas==0)
    {
        printf("NOT FOUND!");
        return 0;
    }
    printf("%d %d %d %d %d\n",max_czas,g1,g2,g3,g4);
    for(int i=0; i<6; i++)
    {
        if((pocz&(1<<i)))
        {
            wynik1+=(1<<i);
        }
    }
    for(int i=6; i<12; i++)
    {
        if((pocz&(1<<i)))
        {
            wynik2+=(1<<(i-6));
        }
    }
    for(int i=12; i<17; i++)
    {
        if((pocz&(1<<i)))
        {
            wynik3+=(1<<(i-12));
        }
    }
    for(int i=17; i<22; i++)
    {
        if((pocz&(1<<i)))
        {
            wynik4+=(1<<(i-17));
        }
    }
    for(int i=22; i<26; i++)
    {
        if((pocz&(1<<i)))
        {
            wynik5+=(1<<(i-22));
        }
    }
    printf("%d: %d %d %d %d %d",pocz,wynik5,wynik4,wynik3,wynik2,wynik1);
    wynik1=0,wynik2=0,wynik3=0,wynik4=0,wynik5=0;
    for(int i=0; i<6; i++)
    {
        if((koniecc&(1<<i)))
        {
            wynik1+=(1<<i);
        }
    }
    for(int i=6; i<12; i++)
    {
        if((koniecc&(1<<i)))
        {
            wynik2+=(1<<(i-6));
        }
    }
    for(int i=12; i<17; i++)
    {
        if((koniecc&(1<<i)))
        {
            wynik3+=(1<<(i-12));
        }
    }
    for(int i=17; i<22; i++)
    {
        if((koniecc&(1<<i)))
        {
            wynik4+=(1<<(i-17));
        }
    }
    for(int i=22; i<26; i++)
    {
        if((koniecc&(1<<i)))
        {
            wynik5+=(1<<(i-22));
        }
    }
    printf("\n%d: %d %d %d %d %d",koniecc,wynik5,wynik4,wynik3,wynik2,wynik1);
    return 0;
}
