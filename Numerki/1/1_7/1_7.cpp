#include <bits/stdc++.h>

using namespace std;

float solve (int n){
    if(n == 0)
        return log(6.0/5.0);
    return (1.0/n) - 5 * (solve(n - 1.0));
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        cout << i << ". " << solve(i) << endl;
    }

    cout << endl << "test" << endl;

    for(float i = 1; i <= n; i++){
        cout << i <<" .In + 5In-1 = " << solve(i) + 5*solve(i-1) << " 1/n = " << 1/i << endl;
    }
	return 0;
}
