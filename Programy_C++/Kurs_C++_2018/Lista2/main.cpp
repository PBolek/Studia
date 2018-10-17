//Piotr Bolek Lista 2 C++
#include <bits/stdc++.h>
#include "Lista2.h"

using namespace std;

//funkcja skladajaca dwa wektory
wektor skladanie_wektorow(wektor w1, wektor w2){
    wektor nowy = wektor(w1.dx + w2.dx, w1.dy + w2.dy);
    /*nowy->dx = w1.dx + w2.dx;
    nowy->dy = w1.dy + w2.dy;*/
    return nowy;
}
//czy dwie proste sa rownolegle
bool czy_proste_rownolegle(prosta p1, prosta p2){
    if(p1.a * p2.b - p2.a * p1.b == 0)
        return true;
    return false;
}
//czy dwie proste sa prostopadle
bool czy_proste_prostopadle(prosta p1, prosta p2){
    if(p1.a * p2.a + p1.b * p2.b == 0)
        return true;
    return false;
}
//funkcja wyliczajaca punkt przeciecia sie prostych nierownoleglych
punkt punkt_przeciecia_prostych(prosta p1, prosta p2){
    if(czy_proste_rownolegle(p1, p2) == true){
        throw std::invalid_argument("czy_proste_rownolegle(p1, p2) == true");
    }
    punkt wynik = punkt();
    double wx, wy, w;
    wx = (-p1.c) * p2.b - (-p2.c) * p1.b;
    wy = p1.a * (-p2.c) - p2.a * (-p1.c);
    w = p1.a * p2.b - p2.a * p1.b;
    wynik.x = wx / w;
    wynik.y = wy / w;
    return wynik;
}

int main()
{
    prosta prosta1 = prosta();
    prosta prosta2 = prosta();
    wektor w1 = wektor();
    wektor w2 = wektor();
    punkt p1 = punkt();
    char c = '0';
    std::cout << "1 - Skladanie dwoch wektorow" << endl;
    std::cout << "2 - Czy dwie proste sa rownolegle?" << endl;
    std::cout << "3 - Czy dwie proste sa prostopadle?" << endl;
    std::cout << "4 - Podaj punkt przedciecia dwoch prostych" << endl;
    std::cout << "5 - Czy wektor jest prostopadly do prostej?" << endl;
    std::cout << "6 - Czy wektor jest rownolegly do prostej?" <<endl;
    std::cout << "7 - Podaj odleglosc punktu od prostej" << endl;
    std::cout << "8 - Czy podany punkt lezy na prostej?" << endl;
    std::cout << "9 - Sprawdz konstruktory" << endl;
    std::cout << "0 - zakoncz dzialanie programu" << endl;
    std::cin >> c;
    while(c != '0'){
        if(c == '1'){
            std::cout << endl << "Podaj parametry dwoch wektorow: " << endl;
            std::cin >> w1.dx >> w1.dy >> w2.dx >> w2.dy;
            w1 = skladanie_wektorow(w1, w2);
            std::cout << endl << "Wynik skladania wektorow: " << w1.dx << " " << w1.dy << endl;
        }
        else if(c == '2'){
            std::cout << endl << "Podaj parametry dwoch prostych: " << endl;
            std::cin >> prosta1.a >> prosta1.b >> prosta1.c >> prosta2.a >> prosta2.b >> prosta2.c;
            if(czy_proste_rownolegle(prosta1, prosta2) == true)
                std::cout << endl << "Podane proste sa rownolegle" << endl;
            else
                std::cout << endl << "Podane proste nie sa rownolegle" << endl;
        }
        else if(c == '3'){
            std::cout << endl << "Podaj parametry dwoch prostych: " << endl;
            std::cin >> prosta1.a >> prosta1.b >> prosta1.c >> prosta2.a >> prosta2.b >> prosta2.c;
            if(czy_proste_prostopadle(prosta1, prosta2) == true)
                std::cout << endl << "Podane proste sa prostopadle" << endl;
            else
                std::cout << endl << "Podane proste nie sa prostopadle" << endl;
        }
        else if(c == '4'){
            std::cout << endl << "Podaj parametry dwoch prostych: " << endl;
            std::cin >> prosta1.a >> prosta1.b >> prosta1.c >> prosta2.a >> prosta2.b >> prosta2.c;
            try{
                p1 = punkt_przeciecia_prostych(prosta1, prosta2);
                std::cout << endl << "Punkt przeciecia prostych: " << p1.x << " " << p1.y << endl;
            }
            catch(std::invalid_argument){
                std::cerr << "Proste sa rownolegle" << endl;
            }
        }
        else if(c == '5'){
            std::cout << endl << "Podaj parametry wektora: " << endl;
            std::cin >> w1.dx >> w1.dy;
            std::cout << endl << "Podaj parametry prostej: " << endl;
            std::cin >> prosta1.a >> prosta1.b >> prosta1.c;
            if(prosta1.czy_prostopadly(w1, prosta1) == true)
                std::cout << endl << "Podany wektor jest prostopadly do podanej prostej" << endl;
            else
                std::cout << endl << "Podany wektor nie jest prostopadly do podanej prostej" << endl;
        }
        else if(c == '6'){
            std::cout << endl << "Podaj parametry wektora: " << endl;
            std::cin >> w1.dx >> w1.dy;
            std::cout << endl << "Podaj parametry prostej: " << endl;
            std::cin >> prosta1.a >> prosta1.b >> prosta1.c;
            if(prosta1.czy_rownolegla(prosta1, w1) == true)
                std::cout << endl << "Podany wektor jest rownolegly do podanej prostej" << endl;
            else
                std::cout << endl << "Podany wektor nie jest rownolegly do podanej prostej" << endl;
        }
        else if(c == '7'){
            std::cout << endl << "Podaj parametry prostej: " << endl;
            std::cin >> prosta1.a >> prosta1.b >> prosta1.c;
            std::cout << endl << "Podaj parametry punktu: " << endl;
            std::cin >> p1.x >> p1.y;
            std::cout << endl << "Odleglosc punktu od prostej = " << prosta1.odleglosc_od_prostej(p1, prosta1);
        }
        else if(c == '8'){
            std::cout << endl << "Podaj parametry prostej: " << endl;
            std::cin >> prosta1.a >> prosta1.b >> prosta1.c;
            std::cout << endl << "Podaj parametry punktu: " << endl;
            std::cin >> p1.x >> p1.y;
            if(prosta1.czy_na_prostej(p1, prosta1) == true)
                std::cout << endl << "Podany punkt lezy na podanej prostej" << endl;
            else
                std::cout << endl << "Podany punkt nie lezy na podanej prostej" << endl;
        }
        else if(c == '9'){
            std::cout << "9.1 (1) Wektor" << endl;
            std::cout << "9.2 (2) Punkt" << endl;
            std::cout << "9.3 (3) Prosta" << endl;
            char k = '0';
            double x, y;
            double dx, dy;
            double a, b, c;
            std::cin >> k;
            if(k == '1'){
                std::cout << "9.1.1 (1) konstruktor domyslny" << endl;
                std::cout << "9.1.2 (2) konstruktor ze wspolrzednymi" << endl;
                std::cout << "9.1.3 (3) konstruktor kopiujacy" << endl;
                std::cin >> k;
                if(k == '1'){
                    wektor w3 = wektor();
                    std::cout << endl << w3.dx << " " << w3.dy << endl;
                }
                else if(k == '2'){
                    std::cout << "Podaj parametry wektora: " << endl;
                    std::cin >> dx >> dy;
                    wektor w4 = wektor(dx, dy);
                    std::cout << endl << w4.dx << " " << w4.dy << endl;
                }
                else if(k == '3'){
                    std::cout << "Podaj wektor do skopiowania: " << endl;
                    std::cin >> dx >> dy;
                    wektor w51 = wektor(dx, dy);
                    wektor w5 = wektor(w51);
                    std::cout << endl << w5.dx << " " << w5.dy;
                }
            }
            else if(k == '2'){
                std::cout << "9.2.1 (1) konstruktor domyslny" << endl;
                std::cout << "9.2.2 (2) konstruktor ze wspolrzednymi" << endl;
                std::cout << "9.2.3 (3) konstrukotr z innym punktem i wektorem" << endl;
                std::cout << "9.2.4 (4) konstruktor kopiujacy" << endl;
                std::cin >> k;
                if(k == '1'){
                    punkt p3 = punkt();
                    std::cout << endl << p3.x << p3.y << endl;
                }
                else if(k == '2'){
                    std::cout << endl << "Podaj wspolrzedne" << endl;
                    std::cin >> x >> y;
                    punkt p4 = punkt(x,y);
                    std::cout << p4.x << " " << p4.y << endl;
                }
                else if(k == '3'){
                    std::cout << endl << "Podaj wspolrzedne" << endl;
                    std::cin >> x >> y;
                    punkt p51 = punkt(x,y);
                    std::cout << endl << "Podaj wektor" << endl;
                    std::cin >> dx >> dy;
                    wektor w52 = wektor(dx, dy);
                    punkt p5 = punkt(p51, w52);
                    std::cout << p5.x << " " << p5.y;
                }
                else if(k == '4'){
                    std::cout << endl << "Podaj wspolrzedne punktu do skopiowania" << endl;
                    std::cin >> x >> y;
                    punkt p61 = punkt(x, y);
                    punkt p6 = punkt(p61);
                    std::cout << endl << p6.x << " " << p6.y;
                }
            }
            else if(k == '3'){
                std::cout << "9.3.1 (1) Konstruktor z para punktow" << endl;
                std::cout << "9.3.2 (2) Konstruktor z wektorem" << endl;
                std::cout << "9.3.3 (3) Konstrukotr z jawnie podanymi wspolczynnikami prostej w postaci ogolnej" << endl;
                std::cout << "9.3.4 (4) Konstruktor domyslny" << endl;
                std::cout << "9.3.5 (5) Konstruktor z prosta i wektorem" << endl;
                std::cin >> k;
                if(k == '1'){
                    std::cout <<"Podaj pare punktow" << endl;
                    std::cin >> x >> y;
                    punkt p7 = punkt(x,y);
                    std::cin >> x >> y;
                    punkt p71 = punkt(x,y);
                    prosta prosta3 = prosta(p7, p71);
                    std::cout << prosta3.a << " " << prosta3.b << " " << prosta3.c << endl;
                }
                else if(k == '2'){
                    std::cout << "Podaj wektor" << endl;
                    std::cin >> dx >> dy;
                    wektor w10 = wektor(dx, dy);
                    prosta prosta4 = prosta(w10);
                    std::cout << prosta4.a << " " << prosta4.b << " " << prosta4.c << endl;
                }
                else if(k == '3'){
                    std::cout << "Podaj wspolczynniki prostej: " << endl;
                    std::cin >> a >> b >> c;
                    prosta prosta5;
                    try{
                        prosta5 = prosta(a, b, c);
                        std::cout << prosta5.a << " " << prosta5.b << " " << prosta5.c << endl;
                    }
                    catch(std::invalid_argument){
                        std::cerr << "a == 0 && b == 0 - niewlasciwe wspolczynniki prostej" << endl;
                    }
                }
                else if(k == '4'){
                    prosta prosta6 = prosta();
                    std::cout << prosta6.a << " " << prosta6.b << " " << prosta6.c << endl;
                }
                else if(k == '5'){
                    std::cout << "Podaj wspolczynniki prostej" << endl;
                    std::cin >> a >> b >> c;
                    prosta prosta7 = prosta (a, b, c);
                    std::cout << "Podaj wektor" << endl;
                    std::cin >> dx >> dy;
                    wektor w11 = wektor(dx, dy);
                    prosta prosta71 = prosta(prosta7, w11);
                    std::cout << prosta71.a << " " << prosta71.b << " " << prosta71.c << endl;
                }
            }
        }
        std::cin >> c;
    }
    return 0;
}
