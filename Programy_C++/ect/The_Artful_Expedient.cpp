#include <bits/stdc++.h>

using namespace std;

int n,tab[2007],tabi[2007],suma;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tab[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tabi[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(tab[i]^tabi[i]==tab[j])
            {
                suma++;
            }
            else if(tab[i]^tabi[i]==tabi[j])
            {
                suma++;
            }
        }
        cout<<suma;
    }
    if(suma%2==0)
    {
        printf("Koyomi");
        return 0;
    }
    else
    {
        printf("Karen");
        return 0;
    }

	return 0;
}
