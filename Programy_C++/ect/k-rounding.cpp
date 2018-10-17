#include <bits/stdc++.h>
using namespace std;
long long n,k,l,m=1;
int main()
{
    cin>>n>>k;
    l=n;
    if(k>=1)
    {
        for(int i=0;i<k;i++)
        {
            m*=(long long)10;
        }
    }
    if(k==0)
    {
        cout<<l;
        return 0;
    }
    while(l%m!=0 || l<m)
    {
        l+=n;
    }
    cout<<l;
	return 0;
}
