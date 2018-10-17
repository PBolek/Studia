#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include "Lista6.h"

using namespace std;

vector<pair<string, double>> zmienna::zm;

liczba :: liczba(double l){
    this->licz = l;
}

double liczba :: oblicz(){
    return licz;
}

std::string liczba :: opis(){
    std::ostringstream strs;
    strs << licz;
    std::string str = strs.str();
    return str;
}

stala :: stala(std::string nazwa, double wart){
    this->nazwa = nazwa;
    this->wart = wart;
}

double stala :: oblicz(){
    return this->wart;
}

std::string stala :: opis(){
    return this->nazwa;
}

double pi :: oblicz(){
    return 3.14;
}

std::string pi :: opis(){
    std::string nazwa = "pi";
    return nazwa;
}

int e :: silnia(int n){
    int wart = 1;
    for(int i = 1; i <= n; i++){
        wart = wart * i;
    }
    return wart;
}

double e :: oblicz(){
    double wynik = 0;
    for(int i = 1; i < 100; i++){
        wynik = wynik + (1 / silnia(i));
    }
    return wynik;
}

std::string e :: opis(){
    std::string nazwa;
    nazwa = "e";
    return nazwa;
}

int fi :: ciag_fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        return (ciag_fib(n - 1) + ciag_fib(n - 2));
    }
}

double fi :: oblicz(){
    return ciag_fib(100);
}

std::string fi :: opis(){
    std::string str = "fi";
    return str;
}

double zmienna :: oblicz(){
    vector<pair<string,double>> help(zm);
    while(help.empty() == false){
        if(help.back().first == nazwa){
            return help.back().second;
        }
        else
            help.pop_back();
    }
    throw std::invalid_argument("Nie ma takiej zmiennej");
}

zmienna :: zmienna (std::string nazwa, double wart){
    this->nazwa = nazwa;
    pair<string, double> para(nazwa, wart);
    zmienna::zm.push_back(para);
}

std::string zmienna :: opis(){
    return this->nazwa;
}

operator1arg :: operator1arg(wyrazenie *a){
    this->a = a;
}

double operator1arg :: oblicz(){
    return this->a->oblicz();
}

std::string operator1arg :: opis(){
    return this->a->opis;
}

double sinus ::
