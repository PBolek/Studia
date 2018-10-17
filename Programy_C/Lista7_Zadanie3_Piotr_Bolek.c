#include <stdio.h>

int n,m,h=0,w=1,wp=0;
char tab[120][120];
int czas[120][120];
int woda[] = {-1,0,0,-1,0,1,1,0};

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("\n");
        for(int j=0; j<m; j++)
        {
            scanf("%c",&tab[i][j]);
            if(tab[i][j]=='#')
            {
                h++;
            }
        }
    }
    for(int i=0;i<120;i++)
    {
        for(int j=0;j<120;j++)
        {
            //if(tab[i][j]=='#')
            //{
                czas[i][j]=-1;
                if(tab[i][j]=='!')
                {
                    czas[i][j]=0;
                }
            //}
        }
    }
    while(w<(n*m)-h)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(czas[i][j]!=-1)
                {
                    continue;
                }
                for(int g=0; g<7; g+=2)
                {
                    if(tab[i+woda[g]][j+woda[g+1]]=='!'&&tab[i][j]!='#')
                    {
                        tab[i][j]='!';
                        w++;
                        czas[i][j]=czas[i+woda[g]][j+woda[g+1]]+1;
                        break;
                    }
                }
            }
        }
        if(wp==w)
        {
            printf("-1");
            return 1;
        }
        wp=w;
    }
    int maks=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maks<czas[i][j])
            {
                maks=czas[i][j];
            }
        }
    }
    printf("%d",maks);
    return 0;
}
