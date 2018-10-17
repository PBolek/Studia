#include "zad7.hpp"

using namespace Obliczenia;
using namespace std;

int main()
{
    try
    {
        cout << "1. Dodaj dwie macierze" << endl;
        cout << "2. Odejmij dwie macierze" << endl;
        cout << "3. Pomnoz macierz przez skalar" << endl;
        cout << "4. Pomnoz dwie macierze" << endl;
        cout << "5. Oblicz wyznacznik macierzy" << endl;
        cout << "6. Olicz macierz odwrotna" << endl;
        cout << "7. Zakoncz dzialanie programu" << endl;
        char c;
        int n, m, skalar;
        cin >> c;
        while(c != '7')
        {
            if(c == '1')
            {
                cout << "A + B" << endl;
                cout << "Macierz A" << endl;
                cout<<"Podaj ilosc wierszy macierzy: "<<endl;
                cin >> n;
                cout<<"Podaj ilosc kolumn macierzy: "<<endl;
                cin>> m;
                Macierz A(n, m);
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                cin >> A;
                cout << "Macierz B" << endl;
                cout << "Podaj ilosc wierszy macierzy: " << endl;
                cin >> n;
                cout << "Podaj ilosc kolumn macierzy: " << endl;
                cin >> m;
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                Macierz B(n, m);
                cin >> B;
                A = A + B;
                cout << endl << "A + B =" << endl << A;
            }
            else if (c == '2')
            {
                cout << "A - B" << endl;
                cout << "Macierz A" << endl;
                cout<<"Podaj ilosc wierszy macierzy: "<<endl;
                cin >> n;
                cout<<"Podaj ilosc kolumn macierzy: "<<endl;
                cin>> m;
                Macierz A(n, m);
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                cin >> A;
                cout << "Macierz B" << endl;
                cout << "Podaj ilosc wierszy macierzy: " << endl;
                cin >> n;
                cout << "Podaj ilosc kolumn macierzy: " << endl;
                cin >> m;
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                Macierz B(n, m);
                cin >> B;
                A = A - B;
                cout << endl << "A - B =" << endl << A;
            }
            else if (c == '3')
            {
                cout << "a * M" <<  endl;
                cout << "Podaj skalar" << endl;
                cin >> skalar;
                cout<<"Podaj ilosc wierszy macierzy: "<<endl;
                cin >> n;
                cout<<"Podaj ilosc kolumn macierzy: "<<endl;
                cin>> m;
                Macierz A(n, m);
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                cin >> A;
                A = A * skalar;
                cout << endl << "a * A =" << endl << A;
            }
            else if (c == '4')
            {
                cout << "A * B" << endl;
                cout << "Macierz A" << endl;
                cout<<"Podaj ilosc wierszy macierzy: "<<endl;
                cin >> n;
                cout<<"Podaj ilosc kolumn macierzy: "<<endl;
                cin>> m;
                Macierz A(n, m);
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                cin >> A;
                cout << "Macierz B" << endl;
                cout << "Podaj ilosc wierszy macierzy: " << endl;
                cin >> n;
                cout << "Podaj ilosc kolumn macierzy: " << endl;
                cin >> m;
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                Macierz B(n, m);
                cin >> B;
                A = A * B;
                cout << endl << "A * B =" << endl << A;
            }
            else if (c == '5')
            {
                cout << "Wyznacznik macierzy" << endl;
                cout<<"Podaj ilosc wierszy macierzy: "<<endl;
                cin >> n;
                cout<<"Podaj ilosc kolumn macierzy: "<<endl;
                cin>> m;
                Macierz A(n, m);
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                cin >> A;
                cout << "Wyznacznik = " << A.Wyznacznik();
            }
            else if (c == '6')
            {
                cout << "Macierz odwrotna" << endl;
                cout<<"Podaj ilosc wierszy macierzy: "<<endl;
                cin >> n;
                cout<<"Podaj ilosc kolumn macierzy: "<<endl;
                cin>> m;
                Macierz A(n, m);
                cout<<"Wprowadz macierz oddzielajac kolumny spacjami a wiersze enterami: "<<endl;
                cin >> A;
                if(A.Wyznacznik() == 0)
                    cout << "Nie mozna obliczyc macierzy odwrotnej, poniewaz wyznacznik jest ronwy zero!" << endl;
                else
                    cout << "Macierz odwrotna =\n" << A.Odwrotna() << endl;
            }
            cout << "1. Dodaj dwie macierze" << endl;
            cout << "2. Odejmij dwie macierze" << endl;
            cout << "3. Pomnoz macierz przez skalar" << endl;
            cout << "4. Pomnoz dwie macierze" << endl;
            cout << "5. Oblicz wyznacznik macierzy" << endl;
            cout << "6. Olicz macierz odwrotna" << endl;
            cout << "7. Zakoncz dzialanie programu" << endl;
            cin >> c;
        }
    }
    catch(BladMat &bm)
    {
        cout << bm.msg << "\n";
    }
    catch(BladIndeksu &bi)
    {
        cout << bi.msg << "\n";
    }
    catch(BladRozmiaru &br)
    {
        cout << br.msg << "\n";
    }
    return 0;
}
