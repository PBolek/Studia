//Piotr Bolek Zadanie 1 Lista 1

#ifndef ZADANIE1_PIOTR_BOLEK_H_INCLUDED
#define ZADANIE1_PIOTR_BOLEK_H_INCLUDED

#if 0
struct kolo {
    float r;
    float x;
    float y;
};

struct kwadrat {
    float x1;
    float y1;
    float x2;
    float y2;
    //...
};

union fig {
    kolo ko;
    kwadrat kw;
};

struct {
    //enum

    fig;
};

fig.ko.r = ...
fig.kw.x1 = ...

#endif

enum typfig
{
    trojkat,
    kwadrat,
    kolo
};

struct Punkt
{
    float x;
    float y;
};

typedef struct Punkt punkt;

struct Figura
{
    enum typfig fig;
    punkt p1, p2, p3, p4;
    float promien;
};

typedef struct Figura figura;

float pot(float x);

float pole(figura *f);

void przesun(figura *f, float x, float y);

float sumapol(figura *f, int size);

#endif // ZADANIE1_PIOTR_BOLEK_H_INCLUDED
