#include <stdio.h>

int segment(int n, int a[], int w)
{
    int l, p, s;
    l=p=0;
    s=0;
    while(s != w && p < n-1)
    {
        if(s<w)
        {
            s=s+a[p], p++;
        }
        else
            s = s-a[l], l++;
        printf("%d ", s);
    }
    while(s > w)
    {
        s = s-a[l], l++;
        printf("%d", s);
    }
    if(s == w)
        return 1;
    else
        return 0;
}

int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    int a[100];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    segment(n,&a[100],w);
    return 0;
}
