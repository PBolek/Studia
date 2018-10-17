#include <iostream>
#include <string>
#include <vector>

class Wyjatek : std::exception {
public:
    std :: string msg;
    Wyjatek(std :: string s);
};

class BladRozmiaru : public Wyjatek {
public:
    BladRozmiaru(std :: string s);
};

class BladIndeksu : public Wyjatek {
public:
    BladIndeksu(std :: string s);
};

class BladMat : public Wyjatek {
public:
    BladMat(std :: string s);
};

namespace Obliczenia {

    class Macierz {

    public:
        int n = 0, m = 0;
        std :: vector<std :: vector<double>> M;

        Macierz(int n);
        Macierz(int n, int m);
        Macierz(const Macierz &m);
        Macierz(Macierz &&m);
        ~Macierz();
        Macierz & operator = (const Macierz &m);
        Macierz & operator = (Macierz &&m);
        Macierz & operator *= (const double &a);
        Macierz & operator += (const Macierz &m);
        Macierz & operator -= (const Macierz &m);
        Macierz & operator *= (const Macierz &m);
        Macierz & operator ! ();
        friend Macierz operator * (const Macierz &m, const double & a);
        friend Macierz operator + (const Macierz &m1, const Macierz &m2);
        friend Macierz operator - (const Macierz &m1, const Macierz &m2);
        friend Macierz operator * (const Macierz &m1, const Macierz &m2);
        void ZamWie(int i, int j);
        void ZamKol(int i, int j);
        void MnozWie(int i, double a);
        void MnozKol(int i, double a);
        void DodMnozWie(int i, int j, double a);
        void DodMnozKol(int i, int j, double a);
        Macierz Wykresl(int i, int j);
        friend std :: istream & operator >> (std :: istream &we, Macierz &x);
        friend std :: ostream & operator << (std :: ostream &wy, const Macierz &x);
        double Wyznacznik();
        Macierz Odwrotna();
    };
}
