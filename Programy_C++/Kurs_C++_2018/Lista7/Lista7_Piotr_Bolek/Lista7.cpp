#include <bits/stdc++.h>
#include "Lista7.h"

using namespace obliczenia;
namespace obliczenia{
    macierz::macierz(int height) : m_height(height), m_width(height){
    double ** tab = new double * [height];
    for(int i = 0; i < height; i++){
        tab[i] = new double [height];
    }
    for(int i = 0; i < height; i++){
        for(int j = 0; j < height; j++){
            if(i == j){
                tab[i][j] = 1.0;
            }
            else
                tab[i][j] = 0.0;
        }
    }
}

macierz::macierz(int height, int width) : m_height(height), m_width(width){
    double ** tab = new double * [width];
    for(int i = 0; i < width; i++){
        tab[i] = new double [height];
    }
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            tab[i][j] = 0.0;
        }
    }
}

int macierz::get_height(){
    return this->m_height;
}

int macierz::get_width(){
    return this->m_width;
}

double** macierz::get_tab(){
    return this->tab;
}

macierz::macierz(macierz& m) : m_height(m.get_height()), m_width(m.get_width()){
    double ** tab = new double * [this->m_width];
    for(int i = 0; i < this->m_width; i++){
        tab[i] = new double [this->m_height];
    }
    this->tab = m.get_tab();
    m.~macierz();
}

macierz::~macierz(){
    for(int i = 0; i < this->m_width; i++){
        delete[] this->tab[i];
    }
    delete[] tab;
}

macierz& macierz::operator+=(const macierz& m){
    if(this->m_height != m.m_height)
        throw std::invalid_argument("Macierze nie maja takich samych wymiarow");
    if(this->m_width != m.m_width)
        throw std::invalid_argument("Macierze nie maja takich samych wymiarow");
    for(int i = 0; i < this->m_width; i++){
        for(int j = 0; j < this->m_height; j++){
            this->tab[i][j] = this->tab[i][j] + m.tab[i][j];
        }
    }
    return *this;
}

macierz& macierz::operator-=(const macierz& m){
    if(this->m_height != m.m_height)
        throw std::invalid_argument("Macierze nie maja takich samych wymiarow");
    if(this->m_width != m.m_height)
        throw std::invalid_argument("Macierze nie maja takich samych wymiarow");
    for(int i = 0; i < this->m_width; i++){
        for(int j = 0; j < this->m_height; j++){
            this->tab[i][j] = this->tab[i][j] - m.tab[i][j];
        }
    }
    return *this;
}

macierz& macierz::operator*=(const macierz& m){
    if(this->m_height != m.m_width)
        throw std::invalid_argument("Wymiary macierzy sie nie zgadzaja");
    if(this->m_width != m.m_height)
        throw std::invalid_argument("Wymiary macierzy sie nie zgadzaja");
    double **t = new double * [this->m_width * m.m_width];
    for(int i = 0; i < this->m_width * m.m_width; i++){
        t[i] = new double [this->m_height * m.m_height];
    }
    for(int i = 0; i < this->m_width * m.m_width; i++){
        for(int j = 0; j < this->m_height * m.m_height; j++){
            t[i][j] = 0;
            for(int k = 0; k < m.m_width; k++){
                t[i][j] += this->tab[i][k] * m.tab[k][j];
            }
        }
    }
    for(int i = 0; i < this->m_width; i++){
        delete[] this->tab[i];
    }
    delete[] tab;
    tab = t;
    return *this;
}

macierz operator + (const macierz& m, const macierz& k){
    if(m.m_height != k.m_height)
        throw std::invalid_argument("Macierze nie maja takich samych wymiarow");
    if(m.m_width != m.m_width)
        throw std::invalid_argument("Macierze nie maja takich samych wymiarow");
    macierz wynik = macierz(m.m_height, m.m_width);
    for(int i = 0; i < m.m_width; i++){
        for(int j = 0; j < m.m_height; j++){
            wynik.tab[i][j] = m.tab[i][j] + k.tab[i][j];
        }
    }
    return wynik;
}

macierz operator - (const macierz& m, const macierz& k){
    if(m.m_height != k.m_height)
        throw std::invalid_argument("Macierze nie maja takich samych wymiarow");
    if(m.m_width != m.m_width)
        throw std::invalid_argument("Macierze nie maja takich samych wymiarow");
    macierz wynik = macierz(m.m_height, m.m_width);
    for(int i = 0; i < m.m_width; i++){
        for(int j = 0; j < m.m_height; j++){
            wynik.tab[i][j] = m.tab[i][j] - k.tab[i][j];
        }
    }
    return wynik;
}

macierz operator * (const macierz& m, const macierz& k){
    macierz wynik = macierz(m.m_height * k.m_height,  m.m_width * k.m_width);
    for(int i = 0; i < m.m_width * k.m_width; i++){
        for(int j = 0; j < m.m_height * m.m_width; j++){
            wynik.tab[i][j] = 0;
            for(int z = 0; z < m.m_width; z++){
                wynik.tab[i][j] += m.tab[i][z] * k.tab[z][j];
            }
        }
    }
    return wynik;
}

/*macierz operator ! (const macierz& m){
    macierz wynik = macierz(m.m_heigth, m.m_width);
    for(int i = 0; i < m.m_witdh; i++){
        for(int j = 0; j < m.m_height; j++){
            wynik.tab[j][i] = m.tab[i][j];
        }
    }
    return wynik;
}*/

void macierz::w_przestaw_dwa_wiersze(int numer1, int numer2){
    if(numer1 > this->m_height || numer2 > this->m_height)
        throw std::invalid_argument("Nie ma takiego wiersza");
    for(int i = 0; i < m_width; i++){
        std::swap(this->tab[i][numer1], this->tab[i][numer2]);
    }
}

void macierz::w_pomnoz_wiersz_przez_a(int numer1, int a){
    if(a == 0)
        throw std::invalid_argument("Skalar jest rowny 0!");
    for(int i = 0; i < this->m_width; i++){
        tab[numer1][i] = tab[numer1][i] * a;
    }
}

void macierz::w_dodaj_krotnosc_innego_wiersza(int numer1, int numer2, int krot){
    for(int i = 0; i < this->m_width; i++){
        tab[i][numer1] = tab[numer2][i] * krot;
    }
    for(int i = 0; i < this->m_width; i++){
        tab[i][numer1] = tab[numer2][i] + tab[numer1][i];
    }
}
void macierz::k_przestaw_dwie_kolumny(int numer1, int numer2){

    std::swap(this->tab[numer1], this->tab[numer2]);
}

void macierz::k_pomnoz_kolumne_przez_a(int a, int numer1){
    for(int i = 0; i < this->m_height; i++){
        this->tab[numer1][i] = this->tab[numer1][i] * a;
    }
}

void macierz::wykreslanie_wiersza_i_kolumny(int numer_kol, int numer_wier){
    const int new_width = this->m_width - 1;
    const int new_height = this->m_height - 1;
    double **t = new double * [new_width];
    for(int i = 0; i < this->m_width; i++){
        t[i] = new double [new_height];
    }
    for(int i = 0; i < this->m_width; i++){
        for(int j = 0; j < this->m_height; j++){
            if(i != numer_wier && j != numer_kol){
                t[i][j] = this->tab[i][j];
            }
        }
    }
}
}




