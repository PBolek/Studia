#include <bits/stdc++.h>

using namespace std;
string p,s,c;
int n,suma,pr,l;

int main()
{
    cin>>p>>n;
    if(n==1)
    {
        cin>>s;
        if(s[0]==p[1])
        {
            suma++;
        }
        if(s[1]==p[0])
        {
            suma++;
        }
        if(s==p)
        {
            printf("YES");
            return 0;
        }
    }
    else
    for(int i=0; i<n; i++)
    {
        cin>>s;
        if(s[0]==p[1]&&s[1]==p[0]||s==p)
        {
            printf("YES");
            return 0;
        }
        else if(s[0]==p[1]&&pr<1)
        {
            pr++;
            suma++;
        }
        else if(s[1]==p[0]&&l<1)
        {
            l++;
            suma++;
        }
    }
    if(suma>=2)
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
