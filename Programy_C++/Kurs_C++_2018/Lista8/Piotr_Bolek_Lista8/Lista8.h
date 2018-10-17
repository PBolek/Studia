#ifndef LISTA8_H_INCLUDED
#define LISTA8_H_INCLUDED

class wyjatek_wymierny : public std::exception{
};

class dzielenie_przez_0 : wyjatek_wymierny{
private:
    const char* error;
public:
    dzielenie_przez_0() = default;
    dzielenie_przez_0(const char* x);
    dzielenie_przez_0(dzielenie_przez_0 &x) = default;
    dzielenie_przez_0 operator = (dzielenie_przez_0 &x);
    virtual ~dzielenie_przez_0() = default;
    virtual const char* what() const throw(){
        return error;
    };
}dzielenie_przez_0;

class przekroczenie_zakresu : wyjatek_wymierny{
private:
    const char* error;
public:
    przekroczenie_zakresu() = default;
    przekroczenie_zakresu(const char* x);
    przekroczenie_zakresu(przekroczenie_zakresu &x) = default;
    przekroczenie_zakresu operator = (przekroczenie_zakresu &x);
    virtual ~przekroczenie_zakresu() = default;
    virtual const char* what() const throw(){
        return error;
    };
}przekroczenie_zakresu;

namespace obliczenia{
        class wymierna{
    private:
        int licz, mian;
    public:
        wymierna(int licz, int mian);
        wymierna(int liczba);
        wymierna();
        wymierna operator += (wymierna w);
        wymierna operator -= (wymierna w);
        wymierna operator *= (wymierna w);
        wymierna operator /= (wymierna w);
        friend wymierna operator + (wymierna w1, wymierna w2);
        friend wymierna operator - (wymierna w1, wymierna w2);
        friend wymierna operator * (wymierna w1, wymierna w2);
        friend wymierna operator / (wymierna w1, wymierna w2);
        wymierna operator - ();
        wymierna operator ! ();
        operator double();
        explicit operator int();
        friend std::ostream& operator<< (std::ostream &wyj, const wymierna &w);
    };
}


#endif // LISTA8_H_INCLUDED
