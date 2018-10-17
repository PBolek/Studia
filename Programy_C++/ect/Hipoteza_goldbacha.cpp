#include <bits/stdc++.h>

using namespace std;

int n,tab[1000],suma, a=0, piq=0;

int main()
{
    cin>>n;
    if(n%2!=0)
    {
        printf("NIEPOPRAWNA LICZBA");
        return 1;
    }
    else if(n<=2)
    {
        printf("NIEPOPRAWNA LICZBA");
        return 1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                suma++;
            }
        }
        if(suma==2)
        {
            tab[a]=i;
            a++;
        }
        suma=0;
    }
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=a;j++)
        {
            if(tab[i]+tab[j]==n)
            {
                piq++;
            }
        }
    }
    if(piq%2==0)
    {
        cout<<piq/2;
    }
    else
    {
        cout<<(piq+1)/2;
    }

	return 0;
}
