//Lista 5 Piotr Bolek

#ifndef LISTA5_ZADANIE1_H_INCLUDED
#define LISTA5_ZADANIE1_H_INCLUDED

class Data{
public:
    static int dniwmiesiacach[2][13];

    static int dniodpoczroku[2][13];

    Data();

    Data(const Data &data);

    Data(int dzien, int miesiac, int Rok);

    int get_dzien();

    int get_miesiac();

    int get_rok();

    int operator- (const Data &data);

    Data operator++ ();

    Data operator-- ();

    Data operator+= (int dni);

    Data operator-= (int dni);

protected:
    int dzien, miesiac, rok;

    static bool czy_przestepny(int rok);

private:
    bool czy_poprawna(int dzien, int miesiac, int rok);

    int ile_dni(const Data &data);
};

class DataGodz : public Data{
public:
    int get_godziny();

    int get_minuty();

    int get_sekundy();

    DataGodz(int rok, int miesiac, int dzien, int godziny, int minuty, int sekundy);

    DataGodz(int godziny, int minuty, int sekundy);

    DataGodz();

    int operator-(const DataGodz &data);

    DataGodz operator++ ();

    DataGodz operator-- ();

    DataGodz operator+= (int sek);

    DataGodz operator-= (int sek);

    bool operator< (const DataGodz &data);

    bool operator== (const DataGodz &data);

protected:
    int godziny, minuty, sekundy;
private:
};

class Wydarzenie{
private:
protected:
    std::vector<std::pair<DataGodz, std::string>> vek;
public:
    DataGodz get_godziny();

    DataGodz get_minuty();

    DataGodz get_sekundy();

    DataGodz operator==(const DataGodz &data);

    void add(DataGodz data, std::string name);

    std::pair<DataGodz, std::string> szukaj(DataGodz data, std::string name);

};

#endif // LISTA5_ZADANIE1_H_INCLUDED
