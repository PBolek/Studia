//Piotr Bolek Lista 2 C++
#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED

class wektor{
public:
    double dx;
    double dy;
    //konstruktor domyslny
    wektor() = default;
    //konstruktor ze wspolrzednymi
    wektor(double dx, double dy){
        this->dx = dx;
        this->dy = dy;
    }
    //konstruktor kopiujacy
    wektor(const wektor &wektor){
        dx = wektor.dx;
        dy = wektor.dy;
    }
};

class punkt{
public:
    double x;
    double y;
    //konstruktor domyslny
    punkt() = default;
    //konstruktor ze wspolrzednymi
    punkt(double x, double y){
        this->x = x;
        this->y = y;
    }
    //konstruktor z innym punktem i wektorem
    punkt(const punkt &p, wektor w){
        this->x = p.x + w.dx;
        this->y = p.y + w.dy;
    }
    //konstruktor kopiujacy
    punkt(const punkt &p){
        x = p.x;
        y = p.y;
    }
};

class prosta{
public:
    double a;
    double b;
    double c;
    //konstruktor z para punktow
    prosta(punkt a, punkt b){
        this->a = a.y - b.y;
        this->b = b.x - a.x;
        this->c = (b.y * a.x) - (a.y * b.x);
    }
    //konstruktor z werktorem
    prosta(wektor w){
        double x = 0.0;
        double y = 0.0;
        x = x + w.dx;
        y = y + w.dy;
        this->a = w.dx;
        this->b = w.dy;
        this->c = -((w.dx * w.dx) + (w.dy * w.dy));
    }
    //konstruktor z jawnie podanymi wspolczynnikami prostej w postaci ogolnej
    prosta(double a, double b, double c){
        if(a == 0 && b == 0){
            throw std::invalid_argument("a == 0 && b == 0");
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }
    //konstruktor bezparametrowy
    prosta() = default;
    //konstruktor z prosta i wektorem
    prosta(const prosta &p, wektor w){
        this->a = p.a;
        this->b = p.b;
        this->c = c - p.a * w.dx - p.b * w.dy;
    }
    //funkcja badajaca czy zadany wektor jest prostopadly do prostej
    bool czy_prostopadly(wektor w, const prosta &p);
    //funkcja badajaca czy prosta jest rownolegla do wektora
    bool czy_rownolegla(const prosta &p, wektor w);
    //funkcja obliczajaca odleglosc punktu od prostej
    double odleglosc_od_prostej(punkt p, const prosta &P);
    //funkcja sprawdzajaca czy punkt znajduje sie na prostej
    bool czy_na_prostej(punkt p, const prosta &P);
};

#endif // LISTA2_H_INCLUDED
