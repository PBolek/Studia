#include <stdio.h>

int tab[1007][1000];
int vis[1007][1000];
int p[]={-1,1,0,1,1,1,-1,0,1,0,-1,-1,0,-1,1,-1};
int wynik=0;

void dfs(int x, int y)
{
    vis[x][y]=1;
    for(int i=0;i<15;i+=2)
    {
        if(tab[x+p[i]][y+p[i+1]]==1&&vis[x+p[i]][y+p[i+1]]==0)
        {
            dfs(x+p[i],y+p[i+1]);
        }
    }
}

int main()
{
    int a,b;
    char s[3];
    scanf("%s%d%d",s,&a,&b);
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=a;j++)
        {
            scanf("%d",&tab[i][j]);
        }
    }
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=a;j++)
        {
            if(tab[i][j]==1&&vis[i][j]==0)
            {
                dfs(i,j);
                wynik++;
            }
        }
    }
    printf("%d",wynik);
    return 0;
}
