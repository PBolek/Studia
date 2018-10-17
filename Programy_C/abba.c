#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct drzewko
{
    int liczba;
    struct drzewko *lewy;
    struct drzewko *prawy;
};

typedef struct drzewko drzewko;

int cmp(const void *a, const void *b)
{
    drzewko aa = *(drzewko*)a;
    drzewko bb = *(drzewko*)b;
    if(aa.liczba>bb.liczba)
        return -1;
    else if(aa.liczba==bb.liczba)
        return 0;
    else
        return 1;
}

drzewko polacz(drzewko a, drzewko b)
{
    drzewko c;
    drzewko *w1;
    drzewko *w2;
    w1=malloc(sizeof(drzewko));
    w2=malloc(sizeof(drzewko));
    w1->lewy = a.lewy , w1->prawy = a.prawy , w1->liczba = a.liczba;
    w2->lewy = b.lewy , w2->prawy = b.prawy , w2->liczba = b.liczba;
    c.liczba = a.liczba + b.liczba;
    c.lewy = w1;
    c.prawy = w2;
    return c;
}

int ide(drzewko *s, int gl)
{
    if(s->lewy == NULL && s->prawy == NULL)
    {
        return gl*(s->liczba);
    }
    return ide(s->lewy,gl+1)+ide(s->prawy,gl+1);
}

char slowo[100000];
int tab[10000];

int main()
{
    int i = 0,a = 0;
    char s=1;
    drzewko d[100000];
    while(s != EOF)
    {
        s=getchar();
        slowo[i]=s;
        tab[(int)slowo[i]]++;
        i++;
    }
    for(int j=0;j<1000;j++)
    {
        if(tab[j]!=0)
        {
            d[a].liczba=tab[j] , d[a].lewy = NULL , d[a].prawy = NULL;
            a++;
        }
    }
    int licznik=0;
    for(int j=a-1;j>0;j--)
    {
        qsort(d,a-licznik,sizeof(drzewko),cmp);
        d[j-1]=polacz(d[j],d[j-1]);
        licznik++;
    }
    int suma=0;
    if(d[0].lewy != NULL && d[0].prawy != NULL)
    {
        suma=ide(d[0].lewy,1)+ide(d[0].prawy,1);
    }
    else
    {
        suma=d[0].liczba;
    }
    printf("%d",suma);
    return 0;
}
