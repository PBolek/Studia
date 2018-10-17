#include "Lista7_Zadanie2_Piotr_Bolek.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *plik;

int ilosc(list *a) // funkcja wypisujaca ile jest elementow w liscie
{
    list kopia=(*a);
    int liczba=0;
    while(kopia!=NULL)
    {
        liczba++;
        kopia=kopia->next;
    }
    return liczba;
}

int push(list *a) // funkcja dodajaca jeden element do listy
{
    PtList *wezel;
    wezel = (PtList*)malloc(sizeof(PtList));
    wezel->nazwa=(char*)malloc(sizeof(char)*36);
    fscanf(plik,"%f %f %f ",&wezel->x,&wezel->y,&wezel->z);
    fgets(wezel->nazwa, 36, plik);
    if((strcmp(wezel->nazwa,"KONIEC\n")==0) || feof(plik))
    {
        return 1;
    }
    wezel->next=(*a);
    (*a) = wezel;
    return 0;
}

void wypisz_dwa(list *a) // funkcja wypisujaca pierwszy i ostatni element listy
{
    list kopia=(*a);
    if((*a)==NULL)
    {
        printf("Lista jest pusta\n");
        return;
    }
    printf("%f %f %f %s\n",(*a)->x,(*a)->y,(*a)->z,(*a)->nazwa);
    while(kopia->next!=NULL)
    {
        kopia=kopia->next;
    }
    printf("%f %f %f %s\n",kopia->x,kopia->y,kopia->z,kopia->nazwa);
}

void wypisz(list *a) // funkcja wypisujaca wszystkie elementy listy
{
    list (*kopia)=a;
    if((*a)==NULL)
    {
        printf("Lista jest pusta\n");
        return;
    }
    while((*kopia)!=NULL)
    {
        printf("%f %f %f %s\n",(*kopia)->x,(*kopia)->y,(*kopia)->z,(*kopia)->nazwa);
        (*kopia)=(*kopia)->next;
    }
}

void punkt(int p, list *a)
{
    list (*kopia)=a;
    int licznik=0;
    while((*kopia)!=NULL)
    {
        if(licznik==p)
        {
            printf("%f %f %f %s\n",(*kopia)->x,(*kopia)->y,(*kopia)->z,(*kopia)->nazwa);
            break;
        }
        (*kopia)=(*kopia)->next;
        licznik++;
    }
}

void wyzszy(int p, list *a)
{
    list *kopia=a;
    while((*kopia)!=NULL)
    {
        if(((*kopia)->x)>p)
        {
            printf("%f %f %f %s\n",(*kopia)->x,(*kopia)->y,(*kopia)->z,(*kopia)->nazwa);
        }
        (*kopia)=(*kopia)->next;
    }
}

void szukaj(char *slowo[], list *a)
{
    list *kopia=a;
    char *w;
    while((*kopia)!=NULL)
    {
        w=strstr((*kopia)->nazwa,*slowo);
        if(w!=NULL)
        {
            printf("%f %f %f %s\n",(*kopia)->x,(*kopia)->y,(*kopia)->z,(*kopia)->nazwa);
        }
        (*kopia)=(*kopia)->next;
    }
}
