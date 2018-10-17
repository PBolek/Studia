#include <bits/stdc++.h>

int tab[30], maxx, k, s;

using namespace std;

int main()
{
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&tab[i]);
    }
    sort(tab,tab+k);
    for(int i=0;i<k;i++)
    {
        if(tab[i]<=25)
        {
            s++;
        }
    }
    maxx=tab[k-1];
    if(s==k)
    {
        printf("0");
        return 0;
    }
    else
    {
        printf("%d",maxx-=25);
        return 0;
    }
	return 0;
}
