#include <bits/stdc++.h>

using namespace std;

int n, k, tabn[10], tabk[10], tabl[10000], a, minn, suma;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&tabn[i]);
    }
    for(int i=0; i<k; i++)
    {
        scanf("%d",&tabk[i]);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(tabn[i]==tabk[j])
            {
                suma++;
                tabl[a]=tabn[i];
                a++;
            }
        }
    }
    if(suma<1)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<k; j++)
            {
                tabl[a]=(tabn[i]*10)+tabk[j];
                a++;
            }
        }
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<n;j++)
            {
                tabl[a]=(tabk[i]*10)+tabn[j];
                a++;
            }
        }
    }
    minn=tabl[0];
    for(int i=1; i<a; i++)
    {
        if(tabl[i]<minn)
        {
            minn=tabl[i];
        }
    }
    printf("%d",minn);
    return 0;
}
