#include <bits/stdc++.h>
using namespace std;
string x;
int srodek;
int main()
{
    cin>>x;
    for(int i=0; i<=(x.size()-1)/2; i++)
    {
        if(x[i]!=x[(x.size()-1)-i])
        {
            cout<<"Cos zjebales, to nie jest palindrom!";
            return 0;
        }
    }
    cout<<"YEAH! To jest palindrom!";
    return 0;

    return 0;
}
