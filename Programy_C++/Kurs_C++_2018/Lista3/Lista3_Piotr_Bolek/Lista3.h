#ifndef LISTA3_H_INCLUDED
#define LISTA3_H_INCLUDED

class stos{
private:
    std::string* tab;
    int pojemnosc;
    int ile;
public:
    stos & operator= (const stos &);
    stos & operator= (stos &&);
    //Konstruktor z okreslona pojemnoscia
    stos(int pojemnosc);

    //Konstruktor bezparametrowy i jednoczesnie delegatowy
    stos();

    //Konstruktor inicjalizujacy stos za pomoca listy napisow
    stos(std::initializer_list<std::string> l);

    //Konstrukot kopiujacy
    stos(const stos &s);

    //Konstruktor przenoszacy
    stos(stos &&s);

    //Destruktor
    ~stos();

    void wloz(std::string s);

    std::string sciagnij();

    std::string sprawdz();

    int rozmiar();
};

#endif // LISTA3_H_INCLUDED
