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
    int x,j=0;
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
            j=-1;
            j = 0;
            while(plansza[j+1][x]=='.'&&plansza[j+1][x+1]=='.')
            {
                if(j==n-1)
                {
                    break;
                }
                j++;
            }
            j--;
            if(j>=0)
                plansza[j][x]='X',plansza[j][x+1]='X';
            if(j+1>=0)
                plansza[j+1][x]='X',plansza[j+1][x+1]='X';
            j=0;
        }
        else if(c=='T')
        {
            j=0;
            while(plansza[j+1][x+1]=='.'&&plansza[j][x]=='.'&&plansza[j][x+2]=='.')
            {
                if(j==n-1)
                {
                    break;
                }
                j++;
            }
            j--;
            if(j>=0)
                plansza[j][x]='X',plansza[j][x+1]='X',plansza[j][x+2]='X';
            if(j+1>=0)
                plansza[j+1][x+1]='X';
            j=0;
        }
        else if(c=='I')
        {
            j=-3;
            j = 0;
            while(plansza[j+3][x]=='.')
            {
                if(j==n-3)
                {
                    break;
                }
                j++;
            }
            j--;
            if(j>=0)
                plansza[j][x]='X';
            if(j+1>=0)
                plansza[j+1][x]='X';
            if(j+2>=0)
                plansza[j+2][x]='X';
            if(j+3>=0)
                plansza[j+3][x]='X';
            j=0;
        }
        else if(c=='F')
        {
            j=0;
            while(plansza[j+2][x]=='.'&&plansza[j][x+1]=='.')
            {
                if(j==n-2)
                {
                    break;
                }
                j++;
            }
            j--;
            if(j>=0)
            plansza[j][x]='X',plansza[j][x+1]='X';
            if(j+1>=0)
                plansza[j+1][x]='X';
            if(j+2>=0)
                plansza[j+2][x]='X';
            j=0;
        }
        else if(c=='W')
        {
            j=-2;
            j = 0;
            while(plansza[j+2][x]=='.'&&plansza[j+2][x+1]=='.'&&plansza[j+2][x+2]=='.'&&plansza[j+2][x+3]=='.'&&plansza[j+2][x+4]=='.')
            {
                if(j==n-2)
                {
                    break;
                }
                j++;
            }
            j--;
            if(j+2>=0)
                plansza[j+2][x]='X',plansza[j+2][x+1]='X',plansza[j+2][x+2]='X',plansza[j+2][x+3]='X',plansza[j+2][x+4]='X';
            if(j+1>=0)
                plansza[j+1][x]='X',plansza[j+1][x+2]='X',plansza[j+1][x+4]='X';
            if(j>=0)
                plansza[j][x]='X',plansza[j][x+2]='X',plansza[j][x+4]='X';
            j=0;
        }
        else if(c=='*')
        {
            j=-1;
            j = 0;
            while(plansza[j+1][x]=='.')
            {
                if(j==n-1)
                {
                    break;
                }
                j++;
            }
            j--;
            if(j>=0)
                plansza[j][x-1]='.',plansza[j][x]='.',plansza[j][x+1]='.';
            if(j+1>=0)
                plansza[j+1][x-1]='.',plansza[j+1][x]='.',plansza[j+1][x+1]='.';
            if(j+2>=0)
                plansza[j+2][x-1]='.',plansza[j+2][x]='.',plansza[j+2][x+1]='.';
            j=0;
        }
        int poz2 = n-1;
        for(int H=n-1; H >=0; H--)
        {
            int dobry=1;
            for(int j=1; j <=m; j++)
                if(plansza[H][j] == '.') dobry=0;
            if(!dobry)
            {
                for(int j=1; j<=m; j++)
                    plansza[poz2][j] = plansza[H][j];
                poz2--;
            }
        }
        for(int H=poz2; H>=0; H--)
            for(int j=1; j<=m; j++)
                plansza[H][j]='.';
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

