#include <stdio.h>

int p,c[22],k[202],h,m,tab[4004][4004],czas,kiedy,minimum=1e9,przystanek=1,a,autobus=0,poczatkowy,h1,h2,m1,m2;

int minuty(int h)
{
    return h*60;
}

int main()
{
    scanf("%d",&p);
    for(int i=0; i<p; i++)
    {
        scanf("%d%d",&c[i],&k[i]);
        for(int j=0; j<k[i]; j++)
        {
            scanf("%d%d",&h,&m);
            tab[i][j]=minuty(h);
            tab[i][j]+=m;
        }
    }
    czas=c[0];
    for(int i=0; i<k[0]; i++)
    {
        kiedy=tab[0][i] + c[0];
        kiedy=kiedy%1440;
        przystanek = 1;
        czas = c[0];
        while(przystanek<p)
        {
            while(a==0)
            {
                if(autobus>k[przystanek])
                {
                    czas+=(1440-kiedy)+tab[przystanek][0]+c[przystanek];
                    kiedy=tab[przystanek][0]+c[przystanek];
                    przystanek++;
                    autobus=0;
                    a++;
                    if(czas<minimum&&przystanek==p)
                    {
                        poczatkowy=tab[0][i];
                        minimum=czas;
                    }
                }
                else if(kiedy<=tab[przystanek][autobus])
                {
                    czas+=tab[przystanek][autobus]-kiedy +c[przystanek];
                    kiedy=tab[przystanek][autobus]+c[przystanek];
                    a++;
                    przystanek++;
                    if(czas<minimum&&przystanek==p)
                    {
                        poczatkowy=tab[0][i];
                        minimum=czas;
                    }
                }
                autobus++;
            }
            kiedy=kiedy%1440;
            autobus=0;
            a=0;
        }
    }
    h1=poczatkowy/60;
    m1=poczatkowy%60;
    h2=minimum/60;
    m2=minimum%60;
    printf("%d %d %d %d",h1,m1,h2,m2);
    return 0;
}
