#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *plik;

struct Dane
{
    char producent[100];
    char marka[100];
    int rok;
    int pojemnosc;
};

int cmp_p(const void *a, const void *b)
{
    struct Dane *dane1 = (struct Dane *)a;
    struct Dane *dane2 = (struct Dane *)b;
    return(strcmp(dane1->producent,dane2->producent));
}

int cmp_m(const void *a, const void *b)
{
    struct Dane *dane1 = (struct Dane *)a;
    struct Dane *dane2 = (struct Dane *)b;
    return(strcmp(dane1->marka,dane2->marka));
}

int cmp_r(const void *a, const void *b)
{
    struct Dane *dane1 = (struct Dane *)a;
    struct Dane *dane2 = (struct Dane *)b;
    return ((dane2->rok)-(dane1->rok));
}

int main(int argc, char* argv[])
{
    char *nazwa=argv[1];
    int n=argc;
    plik=freopen(nazwa,"r",stdin);
    struct Dane samochody[100];
    int i=0;
    while(!feof(stdin))
    {
        scanf("%s%s%d%d",samochody[i].producent,samochody[i].marka,&samochody[i].rok,&samochody[i].pojemnosc);
        i++;

    }
    if(n==2)
    {
        for(int j=0; j<i; j++)
        {
            printf("%s %s %d %d\n",samochody[j].producent,samochody[j].marka,samochody[j].rok,samochody[j].pojemnosc);
        }
        return 0;
    }
    else
    {
        char *sortowanie=argv[2];
        if(*sortowanie=='p')
        {
            qsort(samochody,i,sizeof(struct Dane),cmp_p);
        }
        else if(*sortowanie=='m')
        {
            qsort(samochody,i,sizeof(struct Dane),cmp_m);
        }
        else if(*sortowanie=='r')
        {
            qsort(samochody,i,sizeof(struct Dane),cmp_r);
        }
        for(int j=0; j<i; j++)
        {
            printf("%s %s %d %d\n",samochody[j].producent,samochody[j].marka,samochody[j].rok,samochody[j].pojemnosc);
        }
    }
    return 0;
}
