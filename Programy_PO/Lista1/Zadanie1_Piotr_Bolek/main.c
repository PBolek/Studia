//Piotr Bolek Zadanie 1 Lista 12

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Zadanie1_Piotr_Bolek.h"

int main()
{
    printf("0 = trojkat\n 1 = kwadrat\n 2 = kolo\n");
    figura figury[10];
    figury[0].fig = 0;
    figury[1].fig = 1;
    figury[2].fig = 2;
    for(int i = 0; i < 3; i++)
    {
        if(i == 0)
        {
            printf("\nPodaj punkty tworzace trojkat: ");
            scanf("%f%f%f%f%f%f", &figury[0].p1.x, &figury[0].p1.y, &figury[0].p2.x, &figury[0].p2.y, &figury[0].p3.x, &figury[0].p3.y);
            printf("\n%f %f %f %f %f %f", figury[0].p1.x, figury[0].p1.y, figury[0].p2.x, figury[0].p2.y, figury[0].p3.x, figury[0].p3.y);
            printf("\nPole trojkata: %f", pole(figury));
        }
        else if(i == 1)
        {
            printf("\nPodaj punkty towrzace kwadrat i dlugosc boku: ");
            scanf("%f%f%f%f%f%f%f%f", &figury[1].p1.x, &figury[1].p1.y, &figury[1].p2.x, &figury[1].p2.y, &figury[1].p3.x, &figury[1].p3.y, &figury[1].p4.x, &figury[1].p4.y);
            printf("\nPole kwadratu: %f", pole(figury + 1));
        }
        else
        {
            printf("\nPodaj srodek kola i promien: ");
            scanf("%f%f%f", &figury[2].p1.x, &figury[2].p1.y, &figury[2].promien);
            printf("\nPole kola: %f", pole(figury + 2));
        }
    }
    printf("\nSuma pol = %f", sumapol(figury, 3));
    printf("\nPrzesun wszystkie figury o zadany wektor: ");
    float x, y;
    scanf("%f%f", &x, &y);
    przesun(figury, x, y);
    printf("\nPunkt p1 dla kazdej figury przesuniety o zadany wektor: %f %f %f", figury[0].p1, figury[1].p1, figury[2].p1);
    return 0;
}
