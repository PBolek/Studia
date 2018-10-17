//Piotr Bolek Lista 3 Zadanie 1

#include <stdio.h>

char tab[2001];

void DrawElip(int x0, int y0, int r) // (x0,y0)-srodek, r-promien
{
    for(int i=0; i<x0+r+1; i++)
    {
        for(int j=0; j<y0+r+1; j++)
        {
            if(((i-x0)*(i-x0))+((j-y0)*(j-y0))<=r*r)
            {
                tab[i*80+j]='X';
            }
        }
    }
}

void DrawRect(int x0, int y0, int w, int h) // od (x0,y1) w,h - szerok. i wysok.
{
    for(int i=0; i<x0+w; i++)
    {
        for(int j=0; j<y0+h; j++)
        {
            if(i>=x0&&j>=y0)
            {
                tab[i*80+j]='X';
            }
        }
    }
}

int main()
{
    int x0, y0, r, w;
    scanf("%d%d%d%d",&x0,&y0,&r,&w);
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<80;j++)
        {
            tab[i*80+j]=' ';
        }
    }
    DrawRect(x0,y0,r,w);
    /*for(int i=0; i<x0+r+1; i++)
    {
        for(int j=0; j<y0+r+1; j++)
        {
            if(((i-x0)*(i-x0))+((j-y0)*(j-y0))<=r*r)
            {
                tab[i*80+j]='X';
            }
        }
    }*/
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<80;j++)
        {
            putchar(tab[i*80+j]);
        }
        putchar('\n');
    }
    return 0;
}
