#include <bits/stdc++.h>
using namespace std;
string x;
int spref,ssuf;
int main()
{
    cin>>x;
    for(int i=x.size()-1;i>(x.size()-1)/2;i--)
    {
        if(x[i]=='0')
        {
            ssuf++;
        }
        else
        {
            break;
        }
    }
    cout<<ssuf;
	return 0;
}
