#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char tab[6001];
char tab2[6001];
int dlugosc;

int main()
{
    while(!feof(stdin))
    {
        fgets(tab2,6001,stdin);
        dlugosc=strlen(tab2);
        for(int i=0; i<dlugosc; i++)
        {
            if(tab[i]!=tab2[i])
            {
                printf("%s",tab2);
                break;
            }
        }
        for(int i=0; i<dlugosc; i++)
        {
            tab[i]=tab2[i];
        }
    }
    return 0;
}
