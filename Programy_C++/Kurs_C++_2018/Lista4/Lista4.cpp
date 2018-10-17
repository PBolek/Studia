#include <bits/stdc++.h>
#include "Lista4.h"

using namespace std;

tab_bit :: tab_bit (int rozm){
    this->tab = new slowo[rozm];
    this->dl = 0;
}

tab_bit :: tab_bit (slowo tb){
    this->tab = new slowo[rozmiarSlowa];
    tab[0] = tb;
    dl = 1;
}

tab_bit :: tab_bit (const tab_bit &tb){
    this->tab = new slowo[tb.dl];
    this->dl = tb.dl;
    copy(tb.tab, tb.tab + tb.dl, this->tab);
}


tab_bit :: tab_bit (tab_bit &&tb){
    this->tab = new slowo[tb.dl % 8];
    this->dl = move(tb.dl);
    this->tab = move(tb.tab);
}

tab_bit & tab_bit :: operator = (const tab_bit &tb){
    if(this->dl < tb.dl){
        delete this->tab;
        this->tab = new slowo[tb.dl];
    }
    this->dl = tb.dl;
    copy(tb.tab, tb.tab + tb.dl, this->tab);
    return *this;
}

tab_bit & tab_bit :: operator = (tab_bit &&tb){
    if(this->dl < tb.dl){
        delete this->tab;
        this->tab = new slowo[tb.dl];
    }
    this->dl = tb.dl;
    this->tab = move(tb.tab);
    return *this;
}

tab_bit :: ~tab_bit(){
    this->dl = 0;
    delete this->tab;
}
