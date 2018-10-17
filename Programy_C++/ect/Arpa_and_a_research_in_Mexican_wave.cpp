#include <bits/stdc++.h>

using namespace std;
int n,k,t,s;
string spec;

int main()
{
    scanf("%d%d%d",&n,&k,&t);
    if(k>=t)
    {
        printf("%d",t);
    }
    else if(t>k&&t<n)
    {
        printf("%d",k);
    }
    else
    {
        printf("%d",(n+k)-t);
    }
    return 0;
}
