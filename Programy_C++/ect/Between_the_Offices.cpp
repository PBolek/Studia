#include <bits/stdc++.h>
using namespace std;
int n,F=0,S=0;
string s;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='F'&&s[i+1]=='S')
        {
            S++;
        }
        if(s[i]=='S'&&s[i+1]=='F')
        {
            F++;
        }
    }
    if(F>S)
    {
        cout<<"YES";
        return 0;
    }
    else
    {
        cout<<"NO";
        return 0;
    }
	return 0;
}
