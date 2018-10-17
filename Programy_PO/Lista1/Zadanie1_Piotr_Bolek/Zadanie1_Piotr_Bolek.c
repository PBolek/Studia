//Piotr Bolek Zadanie 1 Lista 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Zadanie1_Piotr_Bolek.h"

float PI = 3.14159;

float pot(float x)
{
    return x*x;
}

float pole(figura *f)
{
    float pol;
    if(f->fig == 0)
    {
        float a, b, c, p;
        a = sqrt(pot(f->p2.x - f->p1.x) + pot(f->p2.y - f->p1.y));
        b = sqrt(pot(f->p3.x - f->p2.x) + pot(f->p3.y - f->p2.y));
        c = sqrt(pot(f->p1.x - f->p3.x) + pot(f->p1.y - f->p3.y));
        p = (a + b + c) / 2;
        pol = sqrt(p * (p - a) * (p - b) * (p - c));
        return pol;
    }
    else if(f->fig == 1)
    {
        scanf("%f", &f->promien);
        pol = pot(f->promien);
        return pol;
    }
    else if(f->fig == 2)
    {
        pol = pot(f->promien) * PI;
        return pol;
    }
    printf("Blad podanej figury");
    return 1;
}

void przesun(figura *f, float x, float y)
{
    if(f->fig == 0)
    {
        f->p1.x = f->p1.x + x;
        f->p1.y = f->p1.y + y;
        f->p2.x = f->p2.x + x;
        f->p2.y = f->p2.y + y;
        f->p3.x = f->p3.x + x;
        f->p3.y = f->p3.y + y;
        return;
    }
    else if(f->fig == 1)
    {
        f->p1.x = f->p1.x + x;
        f->p1.y = f->p1.y + y;
        f->p2.x = f->p2.x + x;
        f->p2.y = f->p2.y + y;
        f->p3.x = f->p3.x + x;
        f->p3.y = f->p3.y + y;
        f->p4.x = f->p4.x + x;
        f->p4.y = f->p4.y + y;
        return;
    }
    else if(f->fig == 2)
    {
        f->p1.x = f->p1.x + x;
        f->p2.y = f->p2.y + y;
        return;
    }
    printf("Blad podanej figury");
}

float sumapol(figura *f, int size)
{
   float suma_pol;
   for(int i = 0; i < size; i++)
   {
       suma_pol = suma_pol + pole(f + i);
   }
   return suma_pol;
}
