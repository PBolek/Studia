#ifndef LISTA4_H_INCLUDED
#define LISTA4_H_INCLUDED

using namespace std;

class tab_bit{
    typedef uint64_t slowo; //komorka w tablicy;
    static const int rozmiarSlowa = (sizeof(slowo)*8); // rozmiar slowa w bitach
    friend istream & operator >> (istream &we, tab_bit &tb);
    friend ostream & operator << (ostream &wy, const tab_bit &tb);
    class ref; //klasa pomocnicza do adresowania bitow
protected:
    int dl; // liczba bitow;
    slowo *tab; // tablica bitow;
public:
    explicit tab_bit (int rozm); // wyzerowana tablica bitow [0...rozm]
    explicit tab_bit (slowo tb); // tablica bitow [0...rozmiarSlowa]
                                 // zainicjalizowana wzorcem
    tab_bit (const tab_bit &tb); // konstruktor kopiujacy
    tab_bit (tab_bit &&tb); //konstruktor przenosz¹cy
    tab_bit & operator = (const tab_bit &tb); // przypisanie kopiujace
    tab_bit & operator = (tab_bit &&tb); //przypisanie przenoszace
    ~tab_bit (); // destruktor
private:
    bool czytaj (int i) const; // metoda pomocnicza do odczytu bitu
    bool pisz (int i, bool b); // metoda pomocnicza do zapisu bitu
public:
    bool operator[] (int i) const; // indeksowanie dla sta³ych tablic bitowych
    ref operator[] (int i); // indeksowanie dla zwyk³ych tablic bitowych
    inline int rozmiar () const; // rozmiar tablicy w bitach
public:
    // operatory bitowe: | i |=, & I &=, ^ i ^= oraz !
public:
    // zaprzyjaŸnione operatory strumieniowe: << i >>
};

#endif // LISTA4_H_INCLUDED
