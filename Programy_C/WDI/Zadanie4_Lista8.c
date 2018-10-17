#include <stdio.h>

int res(int tab[], int l, int p) //n-rozmiar przedzialu, tab liczby w ciagu
{
    int n;
    n = p + l;
    if(l == p)
    {
        return tab[l];
    }
    else
    {
        if(res(tab[],(l+n/2),p) > res(tab[],l,(p-n/2))
        {
            return res(tab[],l,(p-n/2));
        }
        else
            return res(tab[],(l+n/2), p);
    }
}

int main()
{
    return 0;
}
