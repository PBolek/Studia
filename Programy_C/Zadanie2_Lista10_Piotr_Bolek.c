#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char wyjscie[2000];
char tab[11][2000], x;
int n, j = 0, p, zmienne[30], numer[30], l = 0;

int priorytet(char z)
{
    if(z == '~')
        return 4;
    else if(z == '&')
        return 3;
    else if(z == '|')
        return 2;
    else if(z == '>')
        return 1;
    else if(z == '=')
        return 0;
    else
        return -1;
}

int lacznosc(char z)
{
    if(z == '&' || z == '|' || z == '=') // 1 - lewostronna
        return 1;
    else // 0 - prawostronna
        return 0;
}

void ONP(char *c)
{
    //zamiana na ONP
    int s = strlen(c), b = 0, a = 0;
    char stos[1000];
    for(int i = 0; i < s; i++)
    {
        if((c[i] >= 'a' && c[i] <= 'z') || c[i] == '1' || c[i] == '0')
        {
            wyjscie[b++] = c[i];
        }
        else if(c[i] == '(')
        {
            stos[a++] = c[i];
        }
        else if(c[i] == ')')
        {
            while(stos[a-1] != '(' && a != 0)
            {
                wyjscie[b] = stos[a-1];
                b++, a--;
            }
            a--;
        }
        else if(c[i] == '&' || c[i] == '|' || c[i] == '>' || c[i] == '=' || c[i] == '~')
        {
            while((a != 0 || stos[a-1] != '(') && ((lacznosc(c[i]) == 1 && (priorytet(c[i]) <= priorytet(stos[a-1]))) || (lacznosc(c[i]) == 0 && (priorytet(c[i]) < priorytet(stos[a-1])))))
            {
                wyjscie[b] = stos[a-1];
                b++, a--;
            }
            stos[a++] = c[i];
        }
    }
    while(a != 0)// az do wyczyszczenia stosu
    {
        wyjscie[b] = stos[a-1];
        b++, a--;
    }
    wyjscie[b++] = '?';
}

int oblicz(int nn)
{
    int a = 0, s = 0;
    int stos[10000];
    while(wyjscie[s] != '?')
        s++;
    for(int i = 0; i < s; i++)
    {
        if(wyjscie[i] == '0')
            stos[a++] = 0;
        else if(wyjscie[i] == '1')
            stos[a++] = 1;
        else if(wyjscie[i] >= 'a' && wyjscie[i] <= 'z')
            stos[a++] = (1&(nn>>(numer[wyjscie[i] - 'a'])));
        else if(wyjscie[i] == '~')
        {
            if(stos[a-1] == 1)
                stos[a-1] = 0;
            else
                stos[a-1] = 1;
        }
        else if(wyjscie[i] == '&')
        {
            if(stos[a-1] == 1 && stos[a-2] == 1)
                stos[a-2] = 1, a--;
            else
                stos[a-2] = 0, a--;
        }
        else if(wyjscie[i] == '|')
        {
            if(stos[a-1] == 0 && stos[a-2] == 0)
                stos[a-2] = 0, a--;
            else
                stos[a-2] = 1, a--;
        }
        else if(wyjscie[i] == '>')
        {
            if(stos[a-1] == 0 && stos[a-2] == 1)
                stos[a-2] = 0, a--;
            else
                stos[a-2] = 1, a--;
        }
        else if(wyjscie[i] == '=')
        {
            if(stos[a-1] == stos[a-2])
                stos[a-2] = 1, a--;
            else
                stos[a-2] = 0, a--;
        }
    }
    return stos[0];
}

int main()
{
    int licznik = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        x = getchar(), j = 0;
        while(x != ';')
        {
            if(isspace(x) == 0)
            {
                tab[i][j] = x;
                j++;
            }
            x = getchar();
        }
        ONP(tab[i]);
        for(int k = 0; k < j; k++)
        {
            if(tab[i][k] >= 'a' && tab[i][k] <= 'z')
                zmienne[tab[i][k] - 'a']++;
        }
        l = 0;
        for(int k = 0; k < 26; k++)
        {
            if(zmienne[k] != 0)
            {
                numer[k] = l;
                l++;
            }
        }
        p = (1 << l) - 1;
        for(int k = 0; k <= p; k++)
        {
            if(oblicz(k) == 1)
                licznik++;
        }
        printf("%d\n", licznik);
        licznik = 0;
        for(int k = 0; k < 30; k++)
        {
            zmienne[k] = 0;
            numer[k] = 0;
        }
        j = 0;
    }
    return 0;
}
