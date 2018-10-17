#include <bits/stdc++.h>

using namespace std;

int n, k, tab[1000008], maxx, minn, tabm[10000],a=1,b, max1, max2;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&tab[i]);
    }
    if(k==1)
    {
        minn=tab[0];
        for(int i=0; i<n; i++)
        {
            if(minn>tab[i])
            {
                minn=tab[i];
            }
        }
        printf("%d",minn);
        return 0;
    }
    else if (k==2)
    {
        max1=tab[0];
        max2=tab[n-1];
        if(max1>max2)
        {
            printf("%d", max1);
            return 0;
        }
        else
        {
            printf("%d", max2);
            return 0;
        }
    }
    else
    {
        maxx=tab[0];
        for(int i=1; i<n; i++)
        {
            if(tab[i]>maxx)
            {
                maxx=tab[i];
            }
        }
        printf("%d", maxx);
        return 0;
    }


    return 0;
}
