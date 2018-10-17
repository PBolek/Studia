//Piotr Bolek Lista 2 C++
#include <bits/stdc++.h>
#include "Lista2.h"

bool prosta::czy_prostopadly(wektor w, const prosta &p){
    if(w.dx == p.a && w.dy == p.b)
        return true;
    return false;
}

bool prosta::czy_rownolegla(const prosta &p, wektor w){
    if(w.dx == 1 && w.dy == -(p.a / p.b))
        return true;
    return false;
}

double prosta::odleglosc_od_prostej(punkt p, const prosta &P){
    return abs(P.a * p.x + P.b * p.y + P.c) / sqrt(P.a * P.a + P.b * P.b);
}

bool prosta::czy_na_prostej(punkt p, const prosta &P){
    if(abs(P.a * p.x + P.b * p.y + P.c) / sqrt(P.a * P.a + P.b * P.b) == 0.0)
        return true;
    return false;
}
