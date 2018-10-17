#include <bits/stdc++.h>
using namespace std;

const int N=1e6;

int n;
int tab[N];
int sn,sp;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>tab[i];
    }
    for(int i=0; i<n; i++)
    {
        if(tab[i]%2!=0)
        {
            sn++;
        }
    }
    if(sn==0)
    {
        cout<<"Second";
        return 0;
    }
    else
    {
        cout<<"First";
        return 0;
    }

    return 0;
}
