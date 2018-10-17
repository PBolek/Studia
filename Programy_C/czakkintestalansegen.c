#include <stdio.h>

int m,n,k;
/*
2 4 5
I 0
F 1
F 0
I 0
W 0
*/

int main()
{
    int x,suma=0,j=0,wiersze=0;
    char c;
    scanf("%d%d%d",&m,&n,&k);
    char plansza[300][300];
    for(int i=0; i<250; i++)
    {
        for(int b=0; b<250; b++)
        {
            plansza[i][b]='.';
        }
    }
    for(int i=0; i<k; i++)
    {
        scanf("\n%c%d",&c,&x);
        x++;
        if(c=='K')
        {
            while(plansza[j+1][x]=='.'&&plansza[j+1][x+1]=='.')
            {
                if(j==n-1)
                {
                    break;
                }
                j++;
            }
            j--;
            plansza[j][x]='X',plansza[j][x+1]='X',plansza[j+1][x]='X',plansza[j+1][x+1]='X';
            j=0;
        }
        else if(c=='T')
        {
            while(plansza[j+1][x+1]=='.'&&plansza[j][x]=='.'&&plansza[j][x+2]=='.')
            {
                if(j==n-1)
                {
                    break;
                }
                j++;
            }
            j--;
            plansza[j][x+1]='X',plansza[j+1][x]='X',plansza[j+1][x+1]='X',plansza[j+1][x+2]='X';
            j=0;
        }
        else if(c=='I')
        {
            while(plansza[j+3][x]=='.')
            {
                if(j==n-3)
                {
                    break;
                }
                j++;
            }
            j--;
            plansza[j][x]='X',plansza[j+1][x]='X',plansza[j+2][x]='X',plansza[j+3][x]='X';
            j=0;
        }
        else if(c=='F')
        {
            while(plansza[j+2][x]=='.'&&plansza[j][x+1]=='.')
            {
                if(j==n-2)
                {
                    break;
                }
                j++;
            }
            j--;
            plansza[j][x]='X',plansza[j][x+1]='X',plansza[j+1][x]='X',plansza[j+2][x]='X';
            j=0;
        }
        else if(c=='W')
        {
            while(plansza[j+2][x]=='.'&&plansza[j+2][x+1]=='.'&&plansza[j+2][x+2]&&plansza[j+2][x+3]=='.'&&plansza[j+2][x+4]=='.')
            {
                if(j==n-2)
                {
                    break;
                }
                j++;
            }
            j--;
            plansza[j+2][x]='X',plansza[j+2][x+1]='X',plansza[j+2][x+2]='X',plansza[j+2][x+3]='X',plansza[j+2][x+4]='X',plansza[j+1][x]='X',plansza[j+1][x+2]='X',plansza[j+1][x+4]='X',plansza[j][x]='X',plansza[j][x+2]='X',plansza[j][x+4]='X';
            j=0;
        }
        else if(c=='*')
        {
            while(plansza[j+1][x]=='.')
            {
                if(j==n-1)
                {
                    break;
                }
                j++;
            }
            j--;
            plansza[j][x]='.',plansza[j][x-1]='.',plansza[j][x+1]='.',plansza[j+1][x-1]='.',plansza[j+1][x]='.',plansza[j+1][x+1]='.',plansza[j+2][x-1]='.',plansza[j+2][x]='.',plansza[j+2][x+1]='.';
            j=0;
        }
        int poz=0;
        for(int H=n-1; H>=0; H--)
        {
            for(int g=1; g<=m; g++)
            {
                if(plansza[H][g]=='X')
                {
                    suma++;
                }
            }
            if(suma==m)
            {
                for(int g=1;g<=m;g++)
                {
                   plansza[H][g]='.';
                }
                poz++;
            }
            else
            {
                if(poz>0)
                {
                    for(int g=1;g<=m;g++)
                    {
                        plansza[H+poz][g]=plansza[H][g];
                    }
                }
            }
            suma=0;
        }
        for(int p=n+5; p>=5; p--)
        {
            for(int g=0; g<m; g++)
            {
                plansza[p][g]=plansza[p-wiersze][g];
            }
        }
       /* for(int V=6; V<=n+5; V++)
        {
            for(int c=1; c<=m; c++)
            {
                printf("%c",plansza[V][c]);
            }
            printf("\n");
        }
        printf("\n\n");*/
    }
    for(int i=0; i<n; i++)
    {
        for(int c=1; c<=m; c++)
        {
            printf("%c",plansza[i][c]);
        }
        printf("\n");
    }
    return 0;
}
