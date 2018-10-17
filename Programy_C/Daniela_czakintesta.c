/*
    Daniela Tataruda
    Lista 7 Zadanie 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct PtLista{
    float x;
    float y;
    float z;
    char *nazwa;
    struct PtLista* next;
} PtLista;

typedef struct PtLista* Lista;

FILE *plik;

int Lista_size(Lista *L)
{
    int wynik = 0;
    Lista kopia = *L;
    while(kopia != NULL)
    {
        wynik++;
        //printf("%s\n", (kopia)->nazwa);
        kopia = kopia->next;
    }
    return wynik;
}

int dodaj_element(Lista *L)
{
    PtLista *p;
    p = (PtLista*)malloc(sizeof(PtLista));
    p->nazwa = (char*)malloc(36 * sizeof(char));
    fscanf(plik, "%f %f %f ", &p->x, &p->y, &p->z);
    fgets(p->nazwa, 36, plik);
    if(feof(plik) || strcmp(p->nazwa, "KONIEC") == 0)
    {
        return 1;
    }
    p->next = *L;
    *L = p;
    return 0;
}

void pokaz_ostatni(Lista *L)
{
    if(*L == NULL)
    {
        printf("PUSTA LISTA\n");
        return;
    }
    printf("x = %f\n", (*L)->x);
    printf("y = %f\n", (*L)->y);
    printf("z = %f\n", (*L)->z);
    printf("nazwa = %s\n", (*L)->nazwa);
}

void pokaz_pierwszy(Lista *L)
{
    if(*L == NULL)
    {
        printf("PUSTA LISTA\n");
        return;
    }
    Lista kopia = *L;
    while((kopia)->next != NULL)
    {
        kopia = (kopia)->next;
    }
    printf("x = %f\n", (kopia)->x);
    printf("y = %f\n", (kopia)->y);
    printf("z = %f\n", (kopia)->z);
    printf("nazwa = %s\n", (kopia)->nazwa);
}

void wypisz_Liste(Lista *L)
{
    if(*L == NULL)
    {
        printf("PUSTA LISTA\n");
        return;
    }
    Lista *kopia = L;
    while(*kopia != NULL)
    {
        printf("x = %f\n", (*kopia)->x);
        printf("y = %f\n", (*kopia)->y);
        printf("z = %f\n", (*kopia)->z);
        printf("nazwa = %s\n", (*kopia)->nazwa);
        *kopia = (*kopia)->next;
    }
}


int main()
{
    plik = fopen("Test71.txt","r");
    Lista L = NULL;
    do
    {
        if(dodaj_element(&L) == 1)
            break;
    }while(!feof(plik));

    printf("Liczba wczytanych elementow do Listy: %d\n", Lista_size(&L));
    printf("Pierwszy element Listy:\n");
    pokaz_pierwszy(&L);
    printf("Ostatni element Listy:\n");
    pokaz_ostatni(&L);
    printf("czy chcesz wypisac cala liste?\n");
    char odpowiedz[5];
    scanf("%s", odpowiedz);
    if(strcmp(odpowiedz, "tak") == 0)
    {
        wypisz_Liste(&L);
    }
    fclose(plik);
    return 0;
}
