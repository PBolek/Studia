#include <bits/stdc++.h>
#include <initializer_list>
#include "Lista3.h"

std::string T[] = {"A", "B", "C", "D", "F", "G", "H"};

int main()
{
    char c = '0';
    int poj;
    stos nowy;
    stos stand_stos;
    stos help;
    stand_stos = stos(30);
    for(int i = 0; i < 7; i++){
        stand_stos.wloz(T[i]);
    }
    std::string s;
    std::vector<std::string> v;
    std::initializer_list<std::string> lis;
    lis = {"abba", "bbab", "asd", "asdfgh", "wasd"};
    while(c != '8')
    {
        if(c == '1')
        {
            std::cout << "1.1 (1) Konstruktor z okreslona pojemnoscia" << std::endl;
            std::cout << "1.2 (2) Konstruktor bezparametrowy" << std::endl;
            std::cout << "1.3 (3) Konstruktor inicjalizujacy stos za pomoca listy napisow" << std::endl;
            std::cout << "1.4 (4) Konstruktor kopiujacy" << std::endl;
            std::cout << "1.5 (5) Konstruktor przenoszacy" << std::endl;
            std::cin >> c;
            if(c == '1')
            {
                std::cout << "Podaj pojemnosc stosu" << std::endl;
                std::cin >> poj;
                try{
                    nowy = stos(poj);
                }
                catch(std::invalid_argument){
                    std::cerr << "Pojemnosc mniejsza od 0";
                }
            }
            else if(c == '2')
            {
                nowy = stos();
            }
            else if(c == '3')
            {
                std::cout << "Wypelniono stos 5 standardowymi napisami" << std::endl;
                nowy = stos(lis);
            }
            else if(c == '4')
            {
                std::cout << "Skopiowano standardowy stos" << std::endl;
                nowy = stos(stand_stos);
            }
            else if(c == '5')
            {
                std::cout << "Przeniesiono wartosci ze standardowego stosu" << std::endl;
                nowy = stos(stand_stos);
            }
        }
        else if(c == '2')
        {
            std::cout << "Podaj element ktory chcesz dodac" << std::endl;
            std::cin >> s;
            try
            {
                nowy.wloz(s);
            }
            catch(std::range_error)
            {
                std::cerr << "Stos jest pelny!";
            }
        }
        else if(c == '3')
        {
            try
            {
                std::cout << "Sciagnieto: " << nowy.sciagnij() << std::endl;
            }
            catch(std::range_error)
            {
                std::cerr << "Stos jest pusty!";
            }
        }
        else if(c == '4')
        {
            try
            {
                std::cout<< nowy.sprawdz() << std::endl;
            }
            catch(std::range_error)
            {
                std::cerr << "Stos jest pusty!";
            }
        }
        else if(c == '5')
        {
            std::cout << nowy.rozmiar() << std::endl;
        }
        else if(c == '6')
        {
            try
            {
                help = stos(nowy.rozmiar());
                for(int i = 0; i <= nowy.rozmiar() + 1; i++)
                {
                    help.wloz(nowy.sciagnij());
                }
                for(int i = 0; i <= help.rozmiar() + 1; i++)
                {
                    std::cout << help.sprawdz() << " ";
                    nowy.wloz(help.sciagnij());
                }
                help.~stos();
            }
            catch(std::range_error)
            {
                std::cerr << "Stos jest pusty!";
            }
        }
        else if(c == '7')
        {
            nowy.~stos();
        }
        std::cout << std::endl << "1. Stworz nowy stos" << std::endl;
        std::cout << "2. Dodaj element do stosu" << std::endl;
        std::cout << "3. Sciagnij element ze stosu" << std::endl;
        std::cout << "4. Sprawdz element na szczycie stosu" << std::endl;
        std::cout << "5. Podaj rozmiar stosu" << std::endl;
        std::cout << "6. Wypisz zawartosc calego stosu" << std::endl;
        std::cout << "7. Destruktor" << std::endl;
        std::cout << "8. Zakoncz dzialanie programu" << std::endl;
        std::cin >> c;
    }
    nowy.~stos();
    help.~stos();
    stand_stos.~stos();
    std::cout << "Zakonczono dzialanie programu";
    return 0;
}
