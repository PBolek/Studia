#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x0 = 1.0, x1 = -1.0/7.0;
    double x2 = ((13.0/7.0)*x1) + ((2.0/7.0)*x0);
    int i = 0, a = 0;
    cout << "Podaj liczbe iteracji" << endl;
    cin >> i;
    while(i != a){
        cout << "Iteracja " << a << endl;
        cout << "x0 = " << x0 << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        x0 = x1;
        x1 = x2;
        x2 = (13.0/7.0)*x1 + (2.0/7.0)*x0;
        a++;
    }
	return 0;
}
