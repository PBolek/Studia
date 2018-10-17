#include <bits/stdc++.h>

using namespace std;

int n, t, a, czas, dni=0,b, suma;
int tab[100];

int main()
{
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
        tab[i]=86400;
        cin>>czas;
        tab[i]=tab[i]-czas;
    }
    for(int i=0;i<n;i++)
    {
        if(suma>=t)
        {
            break;
        }
        else
        {
            suma+=tab[i];
            dni++;
        }

    }
    cout<<dni;


	return 0;
}
