#include <bits/stdc++.h>

using namespace std;

int a,b;
int tab[100],tab2[100],tab3[201];

int main()
{
    cin>>a>>b;
    int potega=1;
    int licznik=0;
    while(a!=0)
    {
        tab[licznik]=a%2;
        a=a/2;
        licznik++;
    }
    int licznikb=0;
    while(b!=0)
    {
        tab2[licznik]=b%2;
        b=b/2;
        licznikb++;
    }
    int dlugosc;
    if(licznikb>licznik)
    {
        dlugosc=licznikb;
    }
    else
    {
        dlugosc=licznik;
    }
    for(int i=0;i<dlugosc;i++)
    {
        if(tab[i]==1&&tab2[i]==1)
        {
            if(tab3[i]==0)
            {
                tab3[i]=1;
            }
            else
            {
                tab3[i]=0;
                tab3[i+1]=1;
            }
        }
        if(tab[i]==0&&tab2[i]==1)
        {
            tab3[i]=1;
        }
        else if(tab[i]==1&&tab2[i]==0)
        {
            tab3[i]=1;
        }
        else if(tab[i]==0&&tab2[i]==0)
        {
            tab3[i]==0;
        }
    }
    for(int i=0;i<dlugosc+1;i++)
    {
        cout<<tab3[i];
    }
    return 0;
}
