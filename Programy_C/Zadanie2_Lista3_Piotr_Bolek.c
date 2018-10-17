//Piotr Bolek Lista 3 Zadanie 2

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
                tab[j+i*80]='X';
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
                tab[j+i*80]='X';
            }
        }
    }
}

void zero()
{
    for(int i=0; i<25; i++)
    {
        for(int j=0; j<80; j++)
        {
            tab[i*80+j]=' ';
        }
    }
}

void DrawT(int x0, int y0, int r)
{
    for(int i2=0; i2<25; i2++)
    {
        for(int j2=0; j2<80; j2++)
        {
            if(i2==x0&&j2==y0)
            {
                for(int i=0; i<r; i++)
                {
                    for(int k=i; k<r-i; k++)
                    {
                        tab[(i2+i)*80+(j2+k)]='X';
                    }
                }
            }

        }
    }

}

void DrawX(int x0, int y0, int h)
{
    int a=1, w=x0;
    for(int i=y0;i<y0+h;i++)
    {
        for(int j=w;j<w+a;j++)
        {
            tab[j+i*80]='X';
        }
        a+=2;
        w--;
    }
    int p=h/4;
    if(p<1)
    {
        p=1;
    }
    for(int i=y0+h;i<y0+h+p;i++)
    {
        tab[x0+i*80]='|';
    }
}

    void mirror()
    {
        for(int i=24; i>=0; i--)
        {
            for(int j=0; j<80; j++)
            {
                putchar(tab[i*80+j]);
            }
            putchar('\n');
        }
    }

    void print()
    {
        for(int i=0; i<25; i++)
        {
            for(int j=0; j<80; j++)
            {
                putchar(tab[i*80+j]);
            }
            putchar('\n');
        }
    }

    int main()
    {
        zero();
        int x0, y0, r, w;
        char komenda='0';
        printf("q - zakonczenie dzialania programu\n");
        printf("c - rysuje kolo, podaj kolejno: x0, y0 i promien kola\n");
        printf("r - rysuje prostokat, podaj kolejno: x0, y0, szerokosc i wysokosc\n");
        printf("p - print wypisuje obecny stan obrazka\n");
        printf("z - zeruje obrazek\n");
        printf("t - rysuje trojkat rownoboczny o gorym boku w jednym wierszu i katach przy tym boku '45 stopni', podaj kolejno: x0, y0 i dlugosc gornego boku\n");
        printf("x - rysuje choinke, podaj kolejno: x0, y0 i wysokosc\n");
        printf("m - odwraca obrazek do gory nogami\n");
        while(komenda!='q')
        {
            scanf("%c",&komenda);
            if(komenda=='c')
            {
                scanf("%d%d%d",&x0,&y0,&r);
                DrawElip(x0,y0,r);
            }
            else if(komenda=='r')
            {
                scanf("%d%d%d%d",&x0,&y0,&r,&w);
                DrawRect(x0,y0,r,w);
            }
            else if(komenda=='p')
            {
                print();
            }
            else if(komenda=='z')
            {
                zero();
            }
            else if(komenda=='t')
            {
                scanf("%d%d%d",&x0,&y0,&r);
                DrawT(x0,y0,r);
            }
            else if(komenda=='x')
            {
                scanf("%d%d%d",&x0,&y0,&r);
                DrawX(x0,y0,r);
            }
            else if(komenda=='m')
            {
                mirror();
            }
        }
        return 0;
    }
