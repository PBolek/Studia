#include <bits/stdc++.h>

using namespace std;

int n,p[1000007], wskaznik, przejscia, suma;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    while(przejscia!=n)
    {

        while(wskaznik!=p[przejscia])
        {
            wskaznik=p[przejscia];
            wskaznik=p[wskaznik];
            suma++;

        }
        przejscia++;
    }
    cout<<przejscia;

    return 0;
}
