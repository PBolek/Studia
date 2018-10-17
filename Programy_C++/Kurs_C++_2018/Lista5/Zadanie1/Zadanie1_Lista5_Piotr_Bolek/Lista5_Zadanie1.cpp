//Lista 5 Piotr Bolek

#include <bits/stdc++.h>
#include "Lista5_Zadanie1.h"
#include <windows.h>

int Data::dniwmiesiacach[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwyk³e
    {0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestêpne
};

int Data::dniodpoczroku[2][13] = {
    {0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwyk³e
    {0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestêpne
};

Data::Data(){
    SYSTEMTIME st;
    GetLocalTime(&st);
    this->dzien = st.wDay;
    this->miesiac = st.wMonth;
    this->rok = st.wYear;
}

Data::Data(int dzien, int miesiac, int rok){
    if(czy_poprawna(dzien, miesiac, rok) == false)
        throw std::invalid_argument("Niepoprawana data!");
    this->dzien = dzien;
    this->miesiac = miesiac;
    this->rok = rok;
}

Data::Data(const Data &data){
    if(czy_poprawna(data.dzien, data.miesiac, data.rok) == false)
        throw std::invalid_argument("Niepoprawna data!");
}


int Data::get_dzien(){
    return this->dzien;
}

int Data::get_miesiac(){
    return this->miesiac;
}

int Data::get_rok(){
    return this->rok;
}

bool Data::czy_przestepny(int rok){
    if(rok % 4 == 0 && rok % 100 != 0){
        return true;
    }
    else if(rok % 400 == 0){
        return true;
    }
    else
        return false;
}

bool Data::czy_poprawna(int dzien, int miesiac, int rok){
    if(rok < 1582)
        return false;
    if(rok == 1582 && miesiac < 10)
        return false;
    if(rok == 1582 && miesiac == 10 && dzien < 15)
        return false;
    if(czy_przestepny(rok) == true){
        for(int i = 1; i <= 12; i++){
            if(dzien == dniwmiesiacach[1][i] && miesiac == i){
                return true;
            }
        }
    }
    else{
        for(int i = 1; i <= 12; i++){
            if(dzien == dniwmiesiacach[0][i] && miesiac == i){
                return true;
            }
        }

    }
    return false;
}

int Data::ile_dni(const Data &data){
    int dni_this = this->rok * dniodpoczroku[1][12];
    int prz_this = this->rok / 4;
    int p100_this = this->rok / 100;
    int prz400_this = this->rok / 400;
    int przes_this = prz_this - p100_this + prz400_this;
    dni_this += przes_this;
    int dni_data = data.rok * dniodpoczroku[1][12];
    int prz_data = data.rok / 4;
    int p100_data = data.rok / 100;
    int prz400_data = data.rok / 400;
    int przes_data = prz_data - p100_data + prz400_data;
    dni_data += przes_data;
    int wynik;
    if(dni_this > dni_data)
        wynik = dni_this - dni_data;
    else
        wynik = dni_data - dni_this;
    return wynik;
}

int Data::operator- (const Data &data){
    int wynik = ile_dni(data);
    return wynik;
}

Data Data::operator++(){
    if(czy_przestepny(this->rok) == true){
        this->dzien = this->dzien + 1;
        if(czy_poprawna(this->dzien, this->miesiac, this->rok) == true)
            return *this;
        else{
            this->dzien = dniwmiesiacach[1][this->miesiac + 1];
            this->miesiac = this->miesiac + 1;
            if(czy_poprawna(this->dzien, this->miesiac, this->rok) == true)
                return *this;
            else{
                this->miesiac = 1;
                this->dzien = dniwmiesiacach[1][1];
                this->rok = this->rok + 1;
                return *this;
            }
        }
    }
    else{
        this->dzien = this->dzien + 1;
        if(czy_poprawna(this->dzien, this->miesiac, this->rok) == true)
            return *this;
        else{
            this->dzien = dniwmiesiacach[1][this->miesiac + 1];
            this->miesiac = this->miesiac + 1;
            if(czy_poprawna(this->dzien, this->miesiac, this->rok) == true)
                return *this;
            else{
                this->miesiac = 1;
                this->dzien = 1;
                this->rok = this->rok + 1;
                return *this;
            }
        }
    }
}

Data Data::operator--(){
    if(czy_przestepny(this->rok) == true){
        this->dzien = this->dzien - 1;
        if(czy_poprawna(this->dzien, this->miesiac, this->rok) == true)
            return *this;
        else{
            this->dzien = dniwmiesiacach[1][this->miesiac - 1];
            this->miesiac = this->miesiac - 1;
            if(czy_poprawna(this->dzien, this->miesiac, this->rok) == true)
                return *this;
            else{
                this->dzien = dniwmiesiacach[1][12];
                this->miesiac = 12;
                this->rok = this->rok - 1;
                return *this;
            }
        }
    }
    else{
        this->dzien = this->dzien - 1;
        if(czy_poprawna(this->dzien, this->miesiac, this->rok) == true)
            return *this;
        else{
            this->dzien = dniwmiesiacach[0][this->miesiac - 1];
            this->miesiac = this->miesiac - 1;
            if(czy_poprawna(this->dzien, this->miesiac, this->rok) == true)
                return *this;
            else{
                this->dzien = dniwmiesiacach[0][12];
                this->miesiac = 12;
                this->rok = this->rok - 1;
                return *this;
            }
        }
    }
}

Data Data::operator+=(int dni){
    int licz;
    int przes;
    if(czy_przestepny(this->rok) == true)
        przes = 1;
    else
        przes = 0;
    licz = dniwmiesiacach[przes][this->miesiac] - this->dzien;
    this->dzien = this->dzien + licz;
    dni = dni - licz;
    if(dni == 0)
        return *this;
    while(dni > dniwmiesiacach[przes][this->miesiac]){
        if(this->miesiac == 13){
            this->miesiac = 1;
            this->dzien = dniwmiesiacach[przes][1];
            this->rok = this->rok + 1;
        }
        if(czy_przestepny(this->rok) == true)
            przes = 1;
        else
            przes = 0;
        dni = dni - dniwmiesiacach[przes][this->miesiac];
        this->miesiac = this->miesiac + 1;
    }
    this->dzien = dni;
    return *this;
}

Data Data::operator-=(int dni){
    int licz;
    int przes;
    if(czy_przestepny(this->rok) == true)
        przes = 1;
    else
        przes = 0;
    licz = dniwmiesiacach[przes][this->miesiac] - this->dzien;
    this->dzien = this->dzien - licz;
    dni = dni - licz;
    if(dni == 0)
        return *this;
    while(dni > dniwmiesiacach[przes][this->miesiac]){
        if(this->miesiac == 0){
            this->miesiac = 12;
            this->dzien = dniwmiesiacach[1][12];
            this->rok = this->rok - 1;
        }
        if(czy_przestepny(this->rok) == true)
            przes = 1;
        else
            przes = 0;
        dni = dni - dniwmiesiacach[przes][this->miesiac];
        this->miesiac = this->miesiac - 1;
    }
    this->dzien = this->dzien - dni;
    return *this;
}

int DataGodz::get_godziny(){
    return this->godziny;
}

int DataGodz::get_minuty(){
    return this->minuty;
}

int DataGodz::get_sekundy(){
    return this->sekundy;
}

DataGodz::DataGodz(int rok, int miesiac, int dzien, int godziny, int minuty, int sekundy){
    this->rok = rok;
    this->miesiac = miesiac;
    this->dzien = dzien;
    this->godziny = godziny;
    this->minuty = minuty;
    this->sekundy = sekundy;
}

DataGodz::DataGodz(int godziny, int minuty, int sekundy){
    this->dzien = 15;
    this->miesiac = 10;
    this->rok = 1582;
    this->godziny = godziny;
    this->minuty = minuty;
    this->sekundy = sekundy;
}

DataGodz::DataGodz(){
    SYSTEMTIME st;
    GetLocalTime(&st);
    this->godziny = st.wHour;
    this->minuty = st.wMinute;
    this->sekundy = st.wSecond;
    this->dzien = st.wDay;
    this->miesiac = st.wMonth;
    this->rok = st.wYear;
}

int DataGodz::operator- (const DataGodz &data){
    int sek = this->godziny * 3600 + this->minuty * 60 + this->sekundy;
    int sek2 = data.godziny * 3600 + data.minuty * 60 + data.sekundy;
    int wynik = 0;
    if(sek > sek2)
        wynik += sek - sek2;
    else
        wynik += sek2 - sek;
    return wynik;
}

DataGodz DataGodz::operator++(){
    this->sekundy = this->sekundy + 1;
    if(this->sekundy == 60){
        this->sekundy = 0;
        this->minuty = this->minuty + 1;
        if(this->minuty == 60){
            this->minuty = 0;
            this->godziny = this->godziny + 1;
            if(this->godziny == 24){
                this->godziny = 0;
            }
        }
    }
    return *this;
}

DataGodz DataGodz::operator--(){
    this->sekundy = this->sekundy - 1;
    if(this->sekundy == -1){
        this->sekundy = 59;
        this->minuty = this->minuty - 1;
        if(this->minuty == -1){
            this->minuty = 59;
            this->godziny = this->godziny - 1;
            if(this->godziny == -1){
                this->godziny = 23;
            }
        }
    }
    return *this;
}

DataGodz DataGodz::operator-=(int sek){
    for(int i = 0; i < sek; i++){
        this->sekundy = this->sekundy - 1;
        if(this->sekundy == -1){
            this->sekundy = 59;
            this->minuty = this->minuty - 1;
            if(this->minuty == -1){
                this->minuty = 59;
                this->godziny = this->godziny - 1;
                if(this->godziny == -1){
                    this->godziny = 23;
                }
            }
        }
    }
    return *this;
}

DataGodz DataGodz::operator+=(int sek){
    for(int i = 0; i < sek; i++){
        this->sekundy = this->sekundy + 1;
        if(this->sekundy == 60){
            this->sekundy = 0;
            this->minuty = this->minuty + 1;
            if(this->minuty == 60){
                this->minuty = 0;
                this->godziny = this->godziny + 1;
                if(this->godziny == 24){
                    this->godziny = 0;
                }
            }
        }
    }
    return *this;
}

bool DataGodz::operator< (const DataGodz &data){
    if(this->godziny < data.godziny)
        return true;
    if(this->godziny == data.godziny && this->minuty < data.minuty)
        return true;
    if(this->godziny == data.godziny && this->minuty == data.minuty && this->sekundy < data.sekundy)
        return true;
    return false;
}

bool DataGodz::operator== (const DataGodz &data){
    if(this->godziny == data.godziny && this->minuty == data.minuty && this->sekundy == data.sekundy)
        return true;
    return false;
}

void Wydarzenie::add(DataGodz data, std::string name){
    std::pair<DataGodz, std::string> wynik = std::pair<DataGodz, std::string>(data, name);
    this->vek.push_back(wynik);
}

std::pair<DataGodz, std::string> Wydarzenie::szukaj(DataGodz data, std::string name){
    std::vector<std::pair<DataGodz, std::string>> helper;
    helper = this->vek;
    while(helper.empty() == false){
        if(helper.back().second == name && helper.back().first == data)
            return helper.back();
        else
            helper.pop_back();
    }
    throw std::invalid_argument("Nie ma takiego wydarzenia!");
}
