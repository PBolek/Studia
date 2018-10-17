#include <stdio.h>
#include <stdlib.h>

int tab[100], gl[100];

void przenies(int a, int b)
{
    tab[a] = b;
    gl[a] = gl[b]+1;
    for(int i=0;i<100;i++)
    {
        if(tab[i] == a) //jesli a jest jakims ojcem, wtedy przenies syna i do ojca a
        {
            przenies(i,a);
        }
    }
}

int main()
{
    gl[1] = 1; //tab-rodzice gl-glebokosc
    int n,a,b;
    char op;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%c%d%d\n", &op, &a, &b);
        if(op == 'd')
        {
            gl[a] = gl[b]+1;
            tab[a] = b;
        }
        else if(op == 'p')
        {
            tab[a] = b;
            printf("%d\n", gl[a]);
            gl[a] = gl[b]+1;
        }
    }
    for(int i=0;i<100;i++)
    {
        if(gl[i] != 0)
        {
            printf("%d %d\n",i,gl[i]);
        }
    }
    printf("%d", gl[2]);
    return 0;
}
