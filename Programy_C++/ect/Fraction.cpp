#include <bits/stdc++.h>
using namespace std;
int n,a,b,tab[1007];
long double maxi=0,x;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            if(i+j==n&&__gcd(i,j)==1&&i<j) // __gcd(i,j)==1 (najwiekszy wspolny dzielnik = 1)
            {
                x=(long double)(i)/(long double)(j);
                if(x>maxi)
                {
                    maxi=x, a=i, b=j;
                }
            }
        }
    }
    printf("%d %d",a,b);
	return 0;
}
