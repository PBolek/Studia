#include <stdio.h>

struct elem
{
    int val;
    struct elem *next;
}elem;

void val(struct elem *l)
{
    while(l != NULL)
        if(l->val > 0)
            printf("%d", l->val);
        l = l->next;
}

void dolacz(struct elem *l)
{
    struct elem *nowy;
    nowy = (struct elem*)malloc(sizeof(struct elem));
    scanf("%d", &nowy->val);
    nowy->next = NULL;
    while(l != NULL)
        l = l->next;
    l->next = nowy;
}

struct elem* usun(struct elem *l)
{
    struct elem *pom;
    pom = (struct elem*)malloc(sizeof(struct elem));
    pom = l->next;
    while(pom->next != NULL)
        l = l->next;
        pom = l->next;
    l->val = pom->val;
    l->next = NULL;
    return l;
}

struct elem *dodaj(struct elem *l, struct elem *n)
{
    while(l != NULL)
        l = l->next;
    l->next = n;
    while(n != NULL)
        l->val = n->val;
        l = l->next;
        n = n->next;
    return l;
}

struct elem *usun_val(struct elem *l, int val)
{
    struct elem *pom;
    pom = (struct elem*)malloc(sizeof(struct elem));
    if(l->val != val)
        pom->val = l->val;
    l = l->next;
    while(l != NULL)
        if(l->val != val)
            pom->next = l;
            pom = pom->next;
            pom->val = l->val;
        l = l->next;
    return pom;
}

void od_konca(struct elem *l)
{
    const int N = 10e8;
    int tab[N], i = 0;
    while(l != NULL)
        tab[i] = l->val;
        l = l->next;
        i++;
    while(i>=0)
        printf("%d ", i);
        i--;
}

int main()
{
    return 0;
}
