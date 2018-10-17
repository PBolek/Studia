#include <bits/stdc++.h>
using namespace std;
string s;
long long spref,ssuf,zera,srodek;
int blad=0;

bool czek(string x)
{
    for(int i=0; i<=(x.size()-1)/2; i++)
    {
        if(x[i]!=x[(x.size()-1)-i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    cin>>s;
    while(s.back()=='0')
    {
        if(czek(s)==1)
        {
            printf("YES");
            return 0;
        }
        s.pop_back();
    }
    if(czek(s)==1)
    {
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;

}
