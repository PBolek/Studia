//Piotr Bolek Lista 8 Zadanie 1
//(a,b)*(c,d)=(ac-bd,ad+bc)
//(a,b)*(a,b)=(a*a-b*b,a*b+b*a)
#include <stdio.h>
#include <stdlib.h>

double eps=1e-5;

typedef struct zespolona
{
    double a;
    double b;
}zesp;

zesp c;

int czy_nalezy(zesp liczba) // funckja sprawdzajaca czy podana liczba zespolona nalezy do zbioru
{
    double a,b;
    a=liczba.a;
    b=liczba.b;
    for(int i=0;i<200;i++)
    {
        liczba.a=(a*a)-(b*b)-(c.a);
        liczba.b=(a*b)+(b*a)-(c.b);
        a=liczba.a;
        b=liczba.b;

    }
    if((((liczba.a)*(liczba.a))+((liczba.b)*(liczba.b)))<4)
    {
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    (c.a) = 0.1;
    (c.b) = 0.83;
    zesp z;
    if(argc == 1)
    {
        for(double j=1.0; j>=-1.0+eps; j-=(1.0/25.0))
        {
            for(double i=-1.0; i<=1.0+eps; i+=(1.0/40.0))
            {
                (z.a)=j;
                (z.b)=i;
                if(czy_nalezy(z)==0)
                {
                    printf("O");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        return 0;
    }
    else if(argc == 3)
    {
        double x,y;
        x=atof(argv[1]);
        y=atof(argv[2]);
        for(double i=1.0;i>=-1.0;i-=(1.0/y))
        {
            for(double j=-1.0;j<=1.0;j+=(1.0/x))
            {
                (z.a)=i;
                (z.b)=j;
                if(czy_nalezy(z)==0)
                {
                    printf("O");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        return 0;
    }
    else if(argc == 5)
    {
        double x,y;
        x=atof(argv[1]);
        y=atof(argv[2]);
        c.a=atof(argv[3]);
        c.b=atof(argv[4]);
        for(double i=1.0; i>=-1.0; i-=(1.0/y))
        {
            for(double j=-1.0; j<=1.0; j+=(1.0/x))
            {
                (z.a)=i;
                (z.b)=j;
                if(czy_nalezy(z)==0)
                {
                    printf("O");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        return 0;
    }
    else
    {
        printf("Podane argumenty nie sa poprawne");
        return 0;
    }

    return 0;
}
