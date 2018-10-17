#include <stdio.h>

int res(int a)
{
    if(a == 1)
    {
        return 1;
    }
    else
    {
        return res(a-1)+a;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",res(n));
    return 0;
}
