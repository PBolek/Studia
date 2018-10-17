#include <bits/stdc++.h>
using namespace std;
int n,k,a=0;
string s;
int tabi[107];
int main()
{
    cin>>n>>k;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        tabi[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(tabi[i]>k)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
	return 0;
}
