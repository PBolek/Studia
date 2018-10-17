#include <bits/stdc++.h>
using namespace std;
int tab[1000];
void fib(int n)
{
    tab[0] = 1, tab[1] = 1;
    for(int i=2;i<=n+1;i++)
    {
        tab[i]=tab[i-1]+tab[i-2];
    }
    cout<<tab[n+1];
}
int main()
{
    int n;
    cin>>n;
    fib(n);
    return 0;
}
