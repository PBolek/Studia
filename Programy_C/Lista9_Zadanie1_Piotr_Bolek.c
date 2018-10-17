//Piotr Bolek Lista 9 Zadanie 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double kwadrat(double x) //funckja zwracajaca kwadrat liczby
{
    return x*x;
}

FILE *plik;

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        int i=0,a=0;
        int ilosc_wierszy=0, ilosc_punktow=0;
        double dlugosc_sciezki=0,x2_x1,y2_y1;
        char tab2[1000];
        char tab[1000];
        double tab3[10000];
        char t[] = "<trkpt";
        plik = fopen(argv[1],"r");
        fseek(plik,0,SEEK_END);
        printf("Dlugosc pliku w bajtach: %d",ftell(plik));
        rewind(plik);
        while(!feof(plik))
        {
            fgets(tab,999,plik);
            ilosc_wierszy++;
            if(strstr(tab,t) != NULL)
            {
                while(tab[i] != '\n')
                {
                    if(tab[i] == '"')
                    {
                        i++;
                        while(tab[i] != '"')
                        {
                            tab2[a] = tab[i];
                            a++, i++;
                        }
                        a=0;
                        printf("%s ", tab2);
                        tab3[ilosc_punktow]=atof(tab2);
                        printf("%f %d\n", tab3[ilosc_punktow], ilosc_punktow);
                        ilosc_punktow++;
                    }
                    i++;
                }
                i=0;
            }
        }
        for(int i=0;i<ilosc_punktow-2;i+=2)
        {
            x2_x1 = tab3[i+2]-tab3[i];
            y2_y1 = tab3[i+3]-tab3[i+1];
            dlugosc_sciezki+=sqrt(kwadrat(x2_x1)+kwadrat(cos((tab3[i]*3.14)/180)*y2_y1))*(40075.704)/360;
        }
        ilosc_punktow=ilosc_punktow/2;
        printf("\nIlosc wczytanych punktow: %d\nIlosc wierszy: %d\nDlugosc sciezki w kilometrach: %f",ilosc_punktow,ilosc_wierszy,dlugosc_sciezki);
        return 0;
    }
    else
    {
        printf("Blad podanych argumentow");
        return 0;
    }
    return 0;
}
