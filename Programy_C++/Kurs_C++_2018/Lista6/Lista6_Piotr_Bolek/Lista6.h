#ifndef LISTA6_H_INCLUDED
#define LISTA6_H_INCLUDED

class wyrazenie{
public:
    virtual double oblicz() = 0;
    virtual std::string opis() = 0;
protected:
private:
};

class liczba : public wyrazenie{
private:
    double licz;
public:
    liczba(double l);
    double oblicz();
    std::string opis();
};

class stala : public wyrazenie{
private:
    double wart;
    std::string nazwa;
public:
    stala(std::string nazwa, double wart);
    double oblicz();
    std::string opis();
};

class pi : public stala{
public:
    double oblicz();
    std::string opis();
};

class e : public stala{
private:
    int silnia(int n);
public:
    double oblicz();
    std::string opis();
};

class fi : public stala{
private:
    int ciag_fib(int n);
public:
    double oblicz();
    std::string opis();
};

class zmienna : public wyrazenie{
private:
    static std::vector<std::pair<std::string,double>> zm;
    std::string nazwa;
public:
    zmienna(std::string nazwa, double wart);
    double oblicz();
    std::string opis();
};

class operator1arg : public wyrazenie{
private:
    wyrazenie *a;
    double wart;
public:
    operator1arg(wyrazenie *a);
    double oblicz();
    std::string opis();
};

class sinus : public operator1arg{
private:
    double wart;
public:
    sinus(double wart);
    double oblicz();
    std::string opis();
};

class cosinus : public operator1arg{
private:
    double wart;
public:
    cosinus(double wart);
    double oblicz();
    std::string opis();
};

class bezwzgl : public operator1arg{
private:
    double wart;
public:
    bezwzgl(double wart);
    double oblicz();
    std::string opis();
};

class przeciw : public operator1arg{
private:
    double wart;
public:
    przeciw(double wart);
    double oblicz();
    std::string opis();
};

class exp : public operator1arg{
private:
    double pot;
public:
    exp(double pot);
    double oblicz();
    std::string opis();
};

class odwrot : public operator1arg{
};

class ln : public operator1arg{
};

class operator2arg : public operator1arg{
};

class dodaj : public operator2arg{
};

class logarytm : public operator2arg{
};

class odejmij : public operator2arg{
};

class modulo : public operator2arg{
};

class mnoz : public operator2arg{
};

class potega : public operator2arg{
};

class dziel : public operator2arg{
};

#endif // LISTA6_H_INCLUDED
