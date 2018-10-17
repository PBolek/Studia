#include <stdio.h>

int T(int n, int m)
{
    if(m==0)
    {
        return n;
    }
    else if(n==0)
    {
        return m;
    }
    return T(n-1,m)+2*T(n,m-1);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {

        }
    }
    printf("%d",T(n,m));
    return 0;
}
