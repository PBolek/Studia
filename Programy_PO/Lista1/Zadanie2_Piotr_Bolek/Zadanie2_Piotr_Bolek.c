//Piotr Bolek Zadanie 2 Lista 1

#include <stdio.h>
#include <stdlib.h>
#include "Zadanie2_Piotr_Bolek.h"

Ulamki* dodawanie1(Ulamki a, Ulamki b)
{
    Ulamki *wynik;
    wynik = malloc(sizeof(Ulamki));
    if(a.mianownik == b.mianownik)
    {
        wynik->mianownik = b.mianownik;
        wynik->licznik = a.licznik + b.licznik;
        return wynik;
    }
    wynik->mianownik = b.mianownik * a.mianownik;
    wynik->licznik = (b.licznik * a.mianownik) + (a.licznik * b.mianownik);
    return wynik;
}

Ulamki* odejmowanie1(Ulamki a, Ulamki b)
{
    Ulamki *wynik;
    wynik = malloc(sizeof(Ulamki));
    if(a.mianownik == b.mianownik)
    {
        wynik->mianownik = b.mianownik;
        wynik->licznik = a.licznik - b.licznik;
        return wynik;
    }
    wynik->mianownik = b.mianownik * a.mianownik;
    wynik->licznik = (a.licznik * b.mianownik) - (b.licznik * a.mianownik);
    return wynik;
}

Ulamki* mnozenie1(Ulamki a, Ulamki b)
{
    Ulamki *wynik;
    wynik = malloc(sizeof(Ulamki));
    wynik->mianownik = a.mianownik * b.mianownik;
    wynik->licznik = a.licznik * b.licznik;
    return wynik;
}

Ulamki* dzielenie1(Ulamki a, Ulamki b)
{
    Ulamki *wynik;
    wynik = malloc(sizeof(Ulamki));
    wynik->licznik = a.licznik * b.mianownik;
    wynik->mianownik  = a.mianownik * b.licznik;
    return wynik;
}

void dodawanie2(Ulamki *a, Ulamki *b)
{
    if(a->mianownik == b->mianownik)
    {
        b->licznik = b->licznik + a->licznik;
    }
    else
    {
        int mnoznik1, mnoznik2;
        Ulamki *pom;
        pom = malloc(sizeof(Ulamki));
        pom->mianownik = a->mianownik;
        pom->licznik = a->licznik;
        mnoznik1 = a->mianownik;
        mnoznik2 = b->mianownik;
        b->licznik = b->licznik * mnoznik1;
        b->mianownik = b->mianownik * mnoznik1;
        pom->licznik = pom->licznik * mnoznik2;
        b->licznik = b->licznik + pom->licznik;
    }
}

void odejmowanie2(Ulamki *a, Ulamki *b)
{
    if(a->mianownik == b->mianownik)
    {
        int wynik;
        wynik = a->licznik - b->licznik;
        b->licznik = wynik;
    }
    else
    {
        int mnoznik1, mnoznik2;
        mnoznik1 = a->mianownik;
        mnoznik2 = b->mianownik;
        Ulamki *pom;
        pom = malloc(sizeof(Ulamki));
        pom->licznik = a->licznik * mnoznik2;
        b->licznik = b->licznik * mnoznik1;
        b->mianownik = b->mianownik * mnoznik1;
        b->licznik = pom->licznik - b->licznik;
    }
}

void mnozenie2(Ulamki *a, Ulamki *b)
{
    b->mianownik = b->mianownik * a->mianownik;
    b->licznik = b->licznik * a->licznik;
}

void dzielenie2(Ulamki *a, Ulamki *b)
{
    Ulamki *wynik;
    wynik = malloc(sizeof(Ulamki));
    wynik->licznik = b->mianownik * a->licznik;
    wynik->mianownik = b->licznik * a->mianownik;
    b->mianownik = wynik->mianownik;
    b->licznik = wynik->licznik;
}
