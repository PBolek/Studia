#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    while (a != b)
    {
        if (a < b)
            b -= a;
        else
            a -= b;
    }
    return a;
}
