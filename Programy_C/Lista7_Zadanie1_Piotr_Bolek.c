//Piotr Bolek Lista 7 Zadanie 1 program wczytujacy dane o punktach do dynamicznie alokowanej listy.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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
    scanf("%f %f %f ",&wezel->x,&wezel->y,&wezel->z);
    fgets(wezel->nazwa, 36, stdin);
    if((strcmp(wezel->nazwa,"KONIEC\n")==0) || feof(stdin))
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

int main()
{
    list lista=NULL;
    do
    {
        if(push(&lista)==1)
        {
            break;
        }
    }while(!feof(stdin));
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
