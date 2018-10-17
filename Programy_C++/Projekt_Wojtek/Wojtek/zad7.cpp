#include "zad7.hpp"
#include <bits/stdc++.h>

using namespace Obliczenia;
using namespace std;

Wyjatek :: Wyjatek(string s) : msg(s) { }
BladRozmiaru :: BladRozmiaru(string s) : Wyjatek(s) { }
BladIndeksu :: BladIndeksu(string s) : Wyjatek(s) { }
BladMat :: BladMat(string s) : Wyjatek(s) { }

Macierz :: Macierz(int n)
{
    if(n < 0)
        throw BladRozmiaru("Ujemny rozmiar w konstruktorze");
    this->n = n;
    this->m = n;
    this->M.resize(n);
    for(int i = 0; i < n; i++)
        this->M[i].resize(n, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            i == j ? M[i][j] = 1 : M[i][j] = 0;
}

Macierz :: Macierz(int n, int m)
{
    if(n < 0 || m < 0)
        throw BladRozmiaru("Ujemny rozmiar w konstruktorze");
    this->n = n;
    this->m = m;
    this->M.resize(n);
    for(int i = 0; i < n; i++)
        M[i].resize(m, 0);
}

Macierz :: Macierz(const Macierz &m)
{
    *this = m;
}

Macierz :: Macierz(Macierz &&m)
{
    *this = move(m);
}

Macierz :: ~Macierz()
{
    this->M.clear();
}

Macierz & Macierz :: operator = (const Macierz &m)
{
    this->n = m.n;
    this->m = m.m;
    this->M = m.M;
    return *this;
}

Macierz & Macierz :: operator = (Macierz &&m)
{
    this->n = m.n;
    this->m = m.m;
    this->M = move(m.M);
    m.M.clear();
    m.n = 0;
    m.m = 0;
    return *this;
}

Macierz & Macierz :: operator *= (const double &a)
{
    if(a == 0)
        throw BladMat("Skalar = 0");
    for(int i = 0; i < this->n; i++)
        for(int j = 0; j < this->m; j++)
            this->M[i][j] *= a;
    return *this;
}

Macierz & Macierz :: operator += (const Macierz &m)
{
    if(this->n != m.n || this->m != m.m)
        throw BladRozmiaru("Zly rozmiar - operator +=");
    for(int i = 0; i < this->n; i++)
        for(int j = 0; j < this->m; j++)
            this->M[i][j] += m.M[i][j];
    return *this;
}

Macierz & Macierz :: operator -= (const Macierz &m)
{
    if(this->n != m.n || this->m != m.m)
        throw BladRozmiaru("Zly rozmiar - operator -=");
    for(int i = 0; i < this->n; i++)
        for(int j = 0; j < this->m; j++)
            this->M[i][j] -= m.M[i][j];
    return *this;
}

Macierz & Macierz :: operator *= (const Macierz &m)
{
    if(this->m != m.n || this->n != m.m)
        throw BladRozmiaru("Zly rozmiar - operator *= Macierz * Macierz");
    Macierz res(this->n, m.m);
    for(int i = 0; i < this->n; i++)
        for(int j = 0; j < m.m; j++)
            for(int k = 0; k < this->m; k++)
                res.M[i][j] += this->M[i][k] * m.M[k][j];
    if(res.n != this->n || res.m != this->m)
        throw BladRozmiaru("Macierz wynikowa *= nie pasuje do macierzy poczatkowej");
    *this = res;
    return *this;
}

Macierz & Macierz :: operator ! ()
{
    static Macierz res(this->m, this->n);
    for(int i = 0; i < this->n; i++)
        for(int j = 0; j < this->m; j++)
            res.M[j][i] = this->M[i][j];
    return res;
}

namespace Obliczenia
{
    Macierz operator * (const Macierz &m, const double & a)
    {
        if(a == 0)
            throw BladMat("Skalar = 0");
        Macierz res = m;
        for(int i = 0; i < res.n; i++)
            for(int j = 0; j < res.m; j++)
                res.M[i][j] *= a;
        return res;
    }
    Macierz operator + (const Macierz &m1, const Macierz &m2)
    {
        Macierz res = m1;
        if(res.n != m2.n || res.m != m2.m)
            throw BladRozmiaru("Zly rozmiar - funkcja Dodaj");
        for(int i = 0; i < res.n; i++)
            for(int j = 0; j < res.m; j++)
                res.M[i][j] += m2.M[i][j];
        return res;
    }
    Macierz operator - (const Macierz &m1, const Macierz &m2)
    {
        Macierz res = m1;
        if(res.n != m2.n || res.m != m2.m)
            throw BladRozmiaru("Zly rozmiar - funkcja Odejmij");
        for(int i = 0; i < res.n; i++)
            for(int j = 0; j < res.m; j++)
                res.M[i][j] -= m2.M[i][j];
        return res;
    }
    Macierz operator * (const Macierz &m1, const Macierz &m2)
    {
        if(m1.m != m2.n || m1.n != m2.m)
            throw BladRozmiaru("Zly rozmiar - operator *");
        static Macierz res(m1.n, m2.m);
        for(int i = 0; i < m1.n; i++)
            for(int j = 0; j < m2.m; j++)
                for(int k = 0; k < m1.m; k++)
                    res.M[i][j] += m1.M[i][k] * m2.M[k][j];
        return res;
    }
}

void Macierz :: ZamWie(int i, int j)
{
    if(i > this->n || i < 0 | j > this->n || j < 0)
        throw BladIndeksu("Zle indeksy w ZamWie");
    swap(this->M[i], this->M[j]);
}

void Macierz :: ZamKol(int i, int j)
{
    if(i > this->m || i < 0 | j > this->m || j < 0)
        throw BladIndeksu("Zle indeksy w ZamKol");
    for(int k = 0; k < this->m; k++)
        swap(this->M[k][i], this->M[k][j]);
}

void Macierz :: MnozWie(int i, double a)
{
    if(a == 0)
        throw BladMat("a = 0 w MnozWie");
    if(i < 0 || i > this->n)
        throw BladIndeksu("Zly indeks w MnozWie");
    for(int j = 0; j < this->m; j++)
        this->M[i][j] *= a;
}

void Macierz :: MnozKol(int i, double a)
{
    if(a == 0)
        throw BladMat("a = 0 w MnozKol");
    if(i < 0 || i > this->m)
        throw BladIndeksu("Zly indeks w MnozKol");
    for(int j = 0; j < this->n; j++)
        this->M[j][i] *= a;
}

void Macierz :: DodMnozWie(int i, int j, double a)
{
    for(int k = 0; k < this->m; k++)
        this->M[i][k] += this->M[j][k] * a;
}

void Macierz :: DodMnozKol(int i, int j, double a)
{
    for(int k = 0; k < this->m; k++)
        this->M[k][i] += this->M[k][i] * a;
}

Macierz Macierz :: Wykresl(int i, int j)
{
    Macierz res(this->n - 1, this->m - 1);
    int mx = 0, my = 0;
    for(int ki = 0; ki < this->n; ki++)
    {
        for(int kj = 0; kj < this->m; kj++)
        {
            if(ki == i || kj == j) continue;
            ki > i ? mx = 1 : mx = 0;
            kj > j ? my = 1 : my = 0;
            res.M[ki - mx][kj - my] = this->M[ki][kj];
        }
    }
    return res;
}

namespace Obliczenia
{
    istream & operator>> (istream &we, Macierz &x)
    {
        for(int i = 0; i < x.n; i++)
            for(int j = 0; j < x.m; j++)
                we >> x.M[i][j];
        return we;
    }

    ostream & operator<< (ostream &wy, const Macierz &x)
    {
        for(int i = 0; i < x.n; i++)
        {
            for(int j = 0; j < x.m; j++)
                wy << setw(4) << x.M[i][j] << " ";
            wy << "\n";
        }
        return wy;
    }
}

double Macierz :: Wyznacznik()
{
    if(this->m != this->n)
        throw BladRozmiaru("Blad rozmiaru w wyznaczniku");
    double res = 0;
    if(this->n == 1)
        return this->M[0][0];
    Macierz m(0);
    for(int i = 0; i < this->m; i++)
    {
        m = this->Wykresl(0, i);
        if(i % 2 == 0) res += this->M[0][i] * m.Wyznacznik();
        else res -= this->M[0][i] * m.Wyznacznik();
    }
    return res;
}

Macierz Macierz :: Odwrotna()
{
    double det = this->Wyznacznik();
    if(det == 0)
        throw BladMat("Wyznacznik = 0 w Odwrotnej");
    Macierz res(this->n, this->m);
    for(int i = 0; i < this->n; i++)
    {
        for(int j = 0; j < this->m; j++)
        {
            double mul;
            (i + 1 + j + 1) % 2 == 0 ? mul = 1 : mul = -1;
            Macierz r1 = this->Wykresl(i, j);
            res.M[i][j] = mul * r1.Wyznacznik();
            res.M[i][j] /= det;
        }
    }
    return !res;
}
