#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char tab[6001];
char tab2[6001];
int a,c,licznik, dlugosc, dlugosc2;

int main()
{
    licznik=1;
    while(fgets(tab2,6001,stdin)!=NULL)
    {
        if(tab2[0]=='\0'||tab2[0]=='\n')
        {
            tab[0]=tab2[0];
        }
        else
        {
            dlugosc=strlen(tab);
            if(licznik==1)
            {
                for(int i=0; i<dlugosc; i++)
                {
                    printf("%c",tab[i]);
                }
            }
            dlugosc2=strlen(tab2);
            if(dlugosc2!=dlugosc)
            {
                for(int i=0; i<dlugosc2; i++)
                {
                    printf("%c",tab2[i]);
                }
                for(int i=0; i<dlugosc2; i++)
                {
                    tab[i]=tab2[i];
                }
            }
            else
            {
                for(int i=0; i<dlugosc2; i++)
                {
                    if(tab[i]!=tab2[i])
                    {
                        for(int i=0; i<dlugosc2; i++)
                        {
                            printf("%c",tab2[i]);
                        }
                        for(int i=0; i<dlugosc2; i++)
                        {
                            tab[i]=tab2[i];
                        }
                        break;
                    }
                }
                for(int i=0; i<dlugosc2; i++)
                {
                    tab[i]=tab2[i];
                }
            }
            licznik++;
        }
    }
    return 0;
}
