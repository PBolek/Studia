#ifndef LISTA7_H_INCLUDED
#define LISTA7_H_INCLUDED

class myexception : public std::exception{
};

class blad_wymiarow : myexception{
    private:
        const char* error;
    public:
        blad_wymiarow() = default;
        blad_wymiarow(const char* x);
        blad_wymiarow(blad_wymiarow &x) = default;
        blad_wymiarow operator = (blad_wymiarow &x);
        virtual ~blad_wymiarow() = default;
        virtual const char* what();
};

namespace obliczenia{
    class macierz{
private:
    const int m_height;
    const int m_width;
    double **tab;
public:
    void wypisz();
    //Macierz diagonalna
    macierz(int hw);
    //Macierz prostokatna wypelniona zerami
    macierz(int height, int width);
    //Konstruktor kopiujacy
    macierz(macierz& m);
    //Konstruktor przenoszacy
    macierz(macierz&& m);
    //Destruktor
    ~macierz();
    int get_height();
    int get_width();
    double** get_tab();
    friend macierz operator + (const macierz& m, const macierz& k);
    friend macierz operator - (const macierz& m, const macierz& k);
    friend macierz operator * (const macierz& m, const macierz& k);
    friend macierz operator ! (const macierz& m);
    friend std::istream operator>> (std::istream &we, macierz &x);
    friend std::ostream operator<< (std::ostream &wy, const macierz &x);
    macierz & operator += (const macierz& m);
    macierz & operator -= (const macierz& m);
    macierz & operator *= (const macierz& m);
    //Przeksztalcenia pierwszego rodzaju (wiersze)
    void w_przestaw_dwa_wiersze(int numer1, int numer2);
    void w_pomnoz_wiersz_przez_a(int numer1, int a);
    void w_dodaj_krotnosc_innego_wiersza(int numer1, int numer2, int krot);
    //Przeksztalcenia drugiego rodzaju (kolumny)
    void k_przestaw_dwie_kolumny(int numer1, int numer2);
    void k_pomnoz_kolumne_przez_a(int a, int numer1);
    void k_dodaj_krotnosc_innej_kolumny(int numer1, int numer2, int krot);
    void wykreslanie_wiersza_i_kolumny(int numer_kol, int numer_wier);
//protected:
};
}

#endif // LISTA7_H_INCLUDED
