//Piotr Bolek Zadanie 2 Lista 1float PI = 3.14159;

#include <stdio.h>
#include <stdlib.h>
#include "Zadanie2_Piotr_Bolek.h"

int main()
{
    Ulamki a, b;
    Ulamki *wynik;
    wynik = malloc(sizeof(Ulamki));
    printf("Czesc testujaca funkcje zwracajace wskaznik do nowoutworzonego elementu\n");
    printf("Podaj licznik i mianownik pierwszej liczby\n");
    scanf("%d%d", &a.licznik, &a.mianownik);
    printf("Podaj licznik i mianowink drugiej liczby\n");
    scanf("%d%d", &b.licznik, &b.mianownik);
    wynik = dodawanie1(a, b);
    printf("Wynik dodawania: %d/%d\n", wynik->licznik, wynik->mianownik);
    wynik = odejmowanie1(a, b);
    printf("Wynik odejmowania: %d/%d\n", wynik->licznik, wynik->mianownik);
    wynik = mnozenie1(a, b);
    printf("Wynik mnozenia: %d/%d\n", wynik->licznik, wynik->mianownik);
    wynik = dzielenie1(a, b);
    printf("Wynik dzielenia: %d/%d\n", wynik->licznik, wynik->mianownik);
    printf("Czesc testujaca funkcje modyfikujace drugi z podanych argumentow\n");
    Ulamki *c, *d;
    c = malloc(sizeof(Ulamki));
    d = malloc(sizeof(Ulamki));
    for(int i = 0; i < 4; i++)
    {
        if(i == 0)
            printf("Dodawanie\n");
        else if(i == 1)
            printf("Odejmowanie\n");
        else if(i == 2)
            printf("Mnozenie\n");
        else
            printf("Dzielenie\n");
        printf("Podaj licznik i mianowink pierwszej liczby\n");
        scanf("%d%d", &c->licznik, &c->mianownik);
        printf("Podaj licznik i mianownik drugiej liczby\n");
        scanf("%d%d", &d->licznik, &d->mianownik);
        if(i == 0)
        {
            dodawanie2(c, d);
            printf("Wynik dodawania: %d/%d\n", d->licznik, d->mianownik);
        }
        else if(i == 1)
        {
            odejmowanie2(c, d);
            printf("Wynik odejmowania: %d/%d\n", d->licznik, d->mianownik);
        }
        else if(i == 2)
        {
            mnozenie2(c, d);
            printf("wynik mnozenia: %d/%d\n", d->licznik, d->mianownik);
        }
        else
        {
            dzielenie2(c, d);
            printf("Wynik dzielenia: %d/%d\n", d->licznik, d->mianownik);
        }
    }
    return 0;
}
