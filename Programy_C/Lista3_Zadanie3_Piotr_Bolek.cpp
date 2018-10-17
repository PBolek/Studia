#include <stdio.h>

int p,c[22],k[22],czas_h,czas_m,tab[2000][2000],h,m;
int czas_rozpoczecia,minimum,czas,godzina,a,czas_h2,czas_m2;

int minuty(int h)
{
    return h*60;
}
int main()
{
    scanf("%d",&p);
    for(int i=0;i<p;i++)
    {
        scanf("%d%d",&c[i],&k[i]);
        for(int j=0;j<k[i];j++)
        {
            scanf("%d%d",&h,&m);
            tab[i][j]=minuty(h);
            tab[i][j]+=m;
        }
    }
    minimum=tab[1][0]-tab[0][0];
    for(int i=1;i<k[0];i++)
    {
        if(tab[1][i]<tab[0][i])
        {
            printf("%d",tab[0][i]);
            minimum=(tab[1][0]+1440)-(tab[0][0]+c[0]);
            if((tab[1][i]+1440)-(tab[0][i]+c[0])<minimum)
            {
                czas_rozpoczecia=tab[0][i];
                minimum=(tab[1][i]+1440)-(tab[0][i]+c[0]);
            }
        }
        else if(tab[1][i]-(tab[0][i]+c[0])<minimum)
        {
            czas_rozpoczecia=tab[0][i];
            minimum=tab[1][i]-(tab[0][i]+c[0]);
        }
    }
    godzina=czas_rozpoczecia+c[0];
    for(int i=1;i<p;i++)
    {
        for(int j=0;j<k[i];j++)
        {
            if(godzina<tab[i][j])
            {
                czas=tab[i][j]-godzina;
                godzina=tab[i][j];
                a++;
                break;
            }
        }
        if(a==0)
        {
            czas+=godzina*24-(godzina-tab[i][0]);
            godzina=tab[i][0];

        }
        else
        {
            godzina+=c[i];
            czas+=c[i];
        }
        a=0;
    }
    czas+=c[p-1];
    czas_h=czas_rozpoczecia/60;
    czas_m=czas_rozpoczecia%60;
    czas_h2=czas/60;
    czas_m2=czas%60;
    printf("%d %d %d %d",czas_h,czas_m,czas_h2,czas_m2);
    return 0;
}
