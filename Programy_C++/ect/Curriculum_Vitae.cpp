#include <bits/stdc++.h>
using namespace std;
int n, maxi=0;
int pref[105], suf[105], tab[105];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tab[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(tab[i]==0)
        {
            pref[i]=pref[i-1]+1;
        }
        else
        {
            pref[i]=pref[i-1];
        }
    }
    for(int i=n;i>0;i--)
    {
        if(tab[i]==1)
        {
            suf[i]=suf[i+1]+1;
        }
        else
        {
            suf[i]=suf[i+1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        maxi=max(maxi,pref[i]+suf[i]);
    }
    printf("%d",maxi);
	return 0;
}
