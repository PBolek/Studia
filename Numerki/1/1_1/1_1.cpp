#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x1 = 0, x2 = 0, a = 0, b = 0, c = 0;
    cout << "Podaj kolejno a, b, c, dla rownania postaci ax^2 + bx + c = 0";
    cin >> a >> b >> c;
    x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
	return 0;
}
