#include <bits/stdc++.h>

using namespace std;

int main()
{
    double const pi = 3.141592;
    double pi2;
    double suma = 1.0;
    pi2 = 4.0;
    int k = 1;
    while(1){
        if(k % 2 == 0){
            suma = (suma + (1.0 / ((2.0 * k) + 1.0)));
        }
        else{
            suma = (suma - (1.0 / ((2.0 * k) + 1.0)));
        }
        pi2 = 4.0 * suma;
        k = k + 1.0;
        if(abs(pi2 - pi) < 0.00001)
            break;
    }
    cout << k;
	return 0;
}
