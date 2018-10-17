#ifndef LISTA7_ZADANIE2_PIOTR_BOLEK_H_INCLUDED
#define LISTA7_ZADANIE2_PIOTR_BOLEK_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *plik;

typedef struct PtList
{
    float x,y,z;
    char *nazwa;
    struct PtList *next;
}PtList;

typedef struct PtList *list;
int ilosc(list *a);
int push(list *a);
void wypisz_dwa(list *a);
void wypisz(list *a);


#endif // LISTA7_ZADANIE2_PIOTR_BOLEK_H_INCLUDED
