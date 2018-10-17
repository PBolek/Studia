#include <bits/stdc++.h>
#include "Lista3.h"

stos::stos(int pojemnosc){
    if(pojemnosc < 0)
        throw std::invalid_argument("Rozmiar mniejszczy od 0");
    this->pojemnosc = pojemnosc;
    this->ile = 0;
    this->tab = new std::string[pojemnosc];
}

stos::stos() : stos(1){}

stos::stos(std::initializer_list<std::string> l){
    this->pojemnosc = l.size();
    this->ile = 0;
    this->tab = new std::string[l.size()];
    for(auto s : l){
        wloz(s);
    }
}

stos & stos::operator=(const stos &s){
    if(this->pojemnosc < s.pojemnosc){
        delete this->tab;
        this->tab = new std::string[s.pojemnosc];
    }
    this->pojemnosc = s.pojemnosc;
    this->ile = s.ile;
    std::copy(s.tab, s.tab + s.pojemnosc, this->tab);
    return *this;
}

stos::stos(const stos &s){
    this->pojemnosc = s.pojemnosc;
    this->ile = s.ile;
    std::copy(s.tab, s.tab + s.pojemnosc, this->tab);
}

stos & stos::operator=(stos &&s){
    if(this->pojemnosc < s.pojemnosc){
        delete this->tab;
        this->tab = new std::string[s.pojemnosc];
    }
    this->ile = s.ile;
    this->pojemnosc = s.pojemnosc;
    this->tab = std::move(s.tab);
    return *this;
}

stos::stos(stos &&s){
    this->pojemnosc = s.pojemnosc;
    this->ile = s.ile;
    this->tab = std::move(s.tab);
}

stos::~stos(){
    this->ile = 0;
    delete this->tab;
}

void stos::wloz(std::string s){
    if(this->ile == this->pojemnosc)
        throw std::range_error("Stos jest pelny!");
    this->tab[this->ile] = s;
    (this->ile)++;
}

std::string stos::sciagnij(){
    if(this->ile == 0)
        throw std::range_error("Stos jest pusty!");
    this->ile--;
    return this->tab[this->ile];
}

std::string stos::sprawdz(){
    if(this->ile == 0)
        throw std::range_error("Stos jest pusty!");
    return this->tab[this->ile - 1];
}

int stos::rozmiar(){
    return this->ile;
}
