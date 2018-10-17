#include <bits/stdc++.h>

using namespace std;
const int N=100007;
long long int n,x,suma;
long long int tab[N],a[N];

int main()
{
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        suma+=a[i];
    }
    if(suma==x&&n==1)
    {
        cout<<"YES";
        return 0;
    }
    if(suma>=x)
    {
        cout<<"NO";
        return 0;
    }
    if(suma+(n-1)==x)
    {
        cout<<"YES";
        return 0;
    }
    else
    {
        cout<<"NO";
        return 0;
    }
	return 0;
}
