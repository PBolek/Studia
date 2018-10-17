//Piotr Bolek Zadadnie 2 Lista 1

#ifndef ZADANIE2_PIOTR_BOLEK_H_INCLUDED
#define ZADANIE2_PIOTR_BOLEK_H_INCLUDED

struct Ulamki
{
    int licznik;
    int mianownik;
};

typedef struct Ulamki Ulamki;

Ulamki* dodawanie1(Ulamki a, Ulamki b);

Ulamki* odejmowanie1(Ulamki a, Ulamki b);

Ulamki* dzielenie1(Ulamki a, Ulamki b);

Ulamki* mnozenie1(Ulamki a, Ulamki b);

void dodawanie2(Ulamki *a, Ulamki *b);

void odejmowanie2(Ulamki *a, Ulamki *b);

void dzielenie2(Ulamki *a, Ulamki *b);

void mnozenie2(Ulamki *a, Ulamki *b);

#endif // ZADANIE2_PIOTR_BOLEK_H_INCLUDED
