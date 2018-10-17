//Piotr Bolek Lista 1

#include <bits/stdc++.h>

using namespace std;

int64_t s_na_i(string a)
{
    int64_t wynik = 0;
    int64_t mn = 1;
    for(int64_t i = 0; i < a.size(); i++){
        if(a[i] == '-' && i == 0)
            continue;
        if(a[i] < '0' || a[i] > '9'){
            throw std::invalid_argument("Podany argument nie jest liczba");
            return 0;
        }
    }
    if(sizeof(a) > sizeof(int64_t)){
        throw std::invalid_argument("sizeof(a) > sizeof(int64_t) // Podanego argumentu nie da sie zapisac w zmiennej typu int64_t");
        return 0;
    }
    else if(a[0] == '-'){
        for(int64_t i = a.size() - 1; i > 0; i--){
            wynik += (((int)a[i] - '0') * mn);
            mn *= 10;
        }
        if(wynik < 0){
            throw std::invalid_argument("Podanego argumnetu nie da sie zapisac w zmiennej typu int64_t.");
            return 0;
        }
        return wynik * (-1);
    }
    for(int64_t i = a.size() - 1; i >= 0; i--){
        wynik += ((int)a[i] - '0') * mn;
        mn *= 10;
    }
    return wynik;
}

bool pierwsza(int64_t a)
{
    for(int i = 2; i*i <= a; i++){
        if(a%i == 0 && i != a)
            return false;
    }
    return true;
}

void wypisz(int64_t x)
{
    if(x == 1 || x == -1 || x == 0)
        std::cout << x;
    else
        std::cout << x << "*";
}

vector<int64_t> czynniki_pierwsze(int64_t a)
{
    vector<int64_t> wynik;
    while(a != 1){
        for(int i = 2; i <= a; i++){
            if(a % i == 0 && pierwsza(i) == true){
                a = a / i;
                wynik.push_back(i);
                break;
            }
        }
    }
    return wynik;
}

int main(int argc, char *argv[])
{
    if(argc == 1){
        std::cerr << "Nie podano argumentow wywolania fukncji." << endl;
        std::cerr << "Jako argumenty wywolania nalezy podac liczby calkowite dajace sie zapisac w zmiennej typu int64_t";
        return 1;
    }
    else{
        string a;
        vector<int64_t> wynik;
        int64_t a_int = 0;
        int flag = 0;
        for(int i = 1; i < argc; i++){
            for(int j = 0; j < (int)strlen(argv[i]); j++){
                a.push_back(argv[i][j]);
            }
            try{
                a_int = s_na_i(a);
            }
            catch(std::invalid_argument){
                std::cerr << i << ". Podany argument nie jest liczba badz nie jest mozliwe zapisanie go w zmiennej typu int64_t";
                return -1;
            }
            if(a_int < 0){
                a_int = a_int * -1;
                flag = 1;
            }
            if(pierwsza(a_int) == true && a_int != 1 && a_int != 0 && a_int != -1){
                wynik.push_back(a_int);
                if(flag == 1)
                    std::cout << i << ". " << wynik.back() * -1 << " = " << wynik.back() * -1 << endl;
                else
                    std::cout << i << ". " << wynik.back() << " = " << wynik.back() << endl;
            }
            else if(a_int == 1 || a_int == 0 || a_int == -1){
                if(flag == 1)
                    a_int = a_int * -1;
                std::cerr << i << ". " << a_int << " nie ma rozkladu na czynniki pierwsze" << endl;
            }
            else{
                wynik = czynniki_pierwsze(a_int);
                if(flag == 1)
                    std::cout << i << ". " << a_int * -1 << " = ";
                else
                    std::cout << i << ". " << a_int << " = ";
                for_each(wynik.begin(), wynik.end() - 1, wypisz);
                if(flag == 1)
                    std::cout << wynik.back() * -1 << endl;
                else
                    std::cout << wynik.back() << endl;
            }
            wynik.clear();
            a.clear();
            a_int = 0;
            flag = 0;
        }
        return 0;
    }
}
