#include <bits/stdc++.h>
#include "Lista8.h"

dzielenie_przez_0::dzielenie_przez_0(const char* x){
    this->error = x;
}

przekroczenie_zakresu::przekroczenie_zakresu(const char* x){
    this->error = x;
}

namespace obliczenia{

    wymierna::wymierna(int licz, int mian){
        if(mian == 0)
            throw dzielenie_przez_0;
        this->licz = licz;
        this->mian = mian;
    }

    wymierna::wymierna(int liczba){
        this->licz = liczba;
        this->mian = 1;
    }

    wymierna::wymierna(){
        this->licz = 0;
        this->mian = 1;
    }

    wymierna wymierna::operator += (wymierna w){
        int m1, m2;
        if(this->mian != w.mian){
            m1 = this->mian;
            m2 = w.mian;
            this->mian = this->mian * m2;
            this->licz = this->licz * m2;
            w.mian = w.mian * m1;
            w.licz = w.licz * m1;
        }
        if(this->licz + w.licz / w.licz > INT_MAX || this->licz + w.licz / w.licz < INT_MIN)
            throw przekroczenie_zakresu;
        this->licz = this->licz + w.licz;
        return *this;
    }

    wymierna wymierna::operator -= (wymierna w){
        int m1, m2;
        if(this->mian != w.mian){
            m1 = this->mian;
            m2 = w.mian;
            this->mian = this->mian * m2;
            this->licz = this->licz * m2;
            w.mian = w.mian * m1;
            w.licz = w.licz * m1;
        }
        if(this->licz - w.licz / w.mian < INT_MIN || this->licz - w.licz / w.mian > INT_MAX)
            throw przekroczenie_zakresu;
        this->licz = this->licz - w.licz;
        return *this;
    }

    wymierna wymierna::operator *= (wymierna w){
        if((this->licz * w.licz) / (this->mian * w.mian) > INT_MAX || (this->licz * w.licz) / (this->mian * w.mian) < INT_MIN)
            throw przekroczenie_zakresu;
        this->licz = this->licz * w.licz;
        this->mian = this->mian * w.mian;
        return *this;
    }

    wymierna wymierna::operator /= (wymierna w){
        if(w.licz == 0)
            throw dzielenie_przez_0;
        if((this->licz * w.mian) / (this->mian * w.licz) > INT_MAX || (this->licz * w.mian) / (this->mian * w.licz) < INT_MIN)
            throw przekroczenie_zakresu;
        this->licz = this->licz * w.mian;
        this->mian = this->mian * w.licz;
        return *this;
    }

    wymierna operator + (wymierna w1, wymierna w2){
        int m1, m2;
        if(w1.mian != w2.mian){
            m1 = w1.mian;
            m2 = w2.mian;
            w1.mian = w1.mian * m2;
            w1.licz = w1.licz * m2;
            w2.mian = w2.mian * m1;
            w2.licz = w2.licz * m1;
        }
        if(w1.licz + w2.licz / w1.mian < INT_MIN || w1.licz + w2.licz / w1.mian > INT_MAX)
            throw przekroczenie_zakresu;
        wymierna help = wymierna(w1.licz + w2.licz, w1.mian);
        return help;
    }

    wymierna operator - (wymierna w1, wymierna w2){
        int m1, m2;
        if(w1.mian != w2.mian){
            m1 = w1.mian;
            m2 = w2.mian;
            w1.mian = w1.mian * m2;
            w1.licz = w1.licz * m2;
            w2.mian = w2.mian * m1;
            w2.licz = w2.licz * m1;
        }
        if(w1.licz - w2.licz / w1.mian < INT_MIN || w1.licz - w2.licz / w1.mian > INT_MAX)
            throw przekroczenie_zakresu;
        wymierna help = wymierna(w1.licz - w2.licz, w1.mian);
        return help;
    }

    wymierna operator * (wymierna w1, wymierna w2){
        if(w1.licz * w2.licz / w1.mian * w2.mian > INT_MAX || w1.licz * w2.licz / w1.mian * w2.mian < INT_MIN)
            throw przekroczenie_zakresu;
        wymierna help = wymierna (w1.licz * w2.licz, w1.mian * w2.mian);
        return help;
    }

    wymierna operator / (wymierna w1, wymierna w2){
        if(w2.licz == 0)
            throw dzielenie_przez_0;
        if(w1.licz * w2.mian / w1.mian * w2.licz > INT_MAX || w1.licz * w2.mian / w1.mian * w2.licz < INT_MIN)
            throw przekroczenie_zakresu;
        wymierna help = wymierna (w1.licz * w2.mian, w1.mian * w2.licz);
        return help;
    }

    wymierna wymierna::operator - (){
        this->mian = this->mian * (-1);
        return *this;
    }

    wymierna wymierna::operator ! (){
        if(this->licz == 0)
            throw dzielenie_przez_0;
        int licz_help = this->licz;
        int mian_help = this->mian;
        this->licz = mian_help;
        this->mian = licz_help;
        return *this;
    }

    wymierna::operator double(){
        double licz_help = (double)this->licz;
        double mian_help = (double)this->mian;
        double wynik = licz_help / mian_help;
        return wynik;
    }

    wymierna::operator int(){
        int wynik = (int)this->licz / (int)this->mian;
        return wynik;
    }
}
