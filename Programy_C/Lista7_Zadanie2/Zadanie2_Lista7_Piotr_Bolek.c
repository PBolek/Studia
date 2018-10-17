//Piotr Bolek Lista 7 Zadanie 2 funkcja main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista7_Zadanie2_Piotr_Bolek.h"

int main(int argc, char *argv[])
{
    list lista=NULL;
    int liczba;
    plik = fopen(argv[1],"r");
    do
    {
        if(push(&lista)==1)
        {
            break;
        }
    }
    while(!feof(stdin));
    if(argc == 1)
    {
        printf("Liczba wczytanych elementow do listy: %d\nOstatni i pierwszy element listy:",ilosc(&lista));
        wypisz_dwa(&lista);
        char c[4];
        scanf("%s",c);
        if(strcmp(c,"tak")==0)
        {
            wypisz(&lista);
        }
        return 0;
    }
    int nr=2;
    while(argv[nr]!=NULL)
    {
        if(strcmp(argv[nr],"wypisz")==0)
        {
            wypisz(&lista);
        }
        else if(strcmp(argv[nr],"punkt")==0)
        {
            nr++;
            liczba=atoi(argv[nr]);
            punkt(liczba,&lista);
        }
        else if(strcmp(argv[nr],"wyzszy")==0)
        {
            nr++;
            liczba=atoi(argv[nr]);
            wyzszy(liczba,&lista);
        }
        else if(strcmp(argv[nr],"szukaj")==0)
        {
            nr++;
            char *p;
            p=argv[nr];
            szukaj(&p,&lista);
        }
    }
    return 0;
}
