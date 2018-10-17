#include <bits/stdc++.h>
using namespace std;
int n,x,minn=0,s=0;
int tab[107];
int tabi[107];
int main()
{
    cin>>n>>x;
    for(int i=0; i<n; i++)
    {
        cin>>tab[i];
    }
    for(int i=0; i<n; i++)
    {
        tabi[tab[i]]++;
    }
    for(int i=0; i<x; i++)
    {
        if(tabi[i]==0)
        {
            s++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(tab[i]==x)
        {
            s++;
        }
    }
    cout<<s;
    return 0;
}
