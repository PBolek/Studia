#include <stdio.h>

int res(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else if(n%2 == 0)
    {
        return 2*res(n/2)+1;
    }
    else if(n%2 != 0)
    {
        return res((n-1)/2)+res((n+1)/2)+1;
    }
}

int main()
{
    printf("%d", res(16));
    return 0;
}
