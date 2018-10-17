#include <bits/stdc++.h>
using namespace std;
int n;
int tab[107];
int tabi[107];
int s=0;
int a=0;
int tabo[5];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    for(int i=0;i<n;i++)
    {
        tabi[tab[i]]++;
    }
    for(int i=1;i<=100;i++)
    {
        if(tabi[i]>0)
        {
            s++;
        }
    }
    if(s!=2)
    {
        cout<<"NO";
        return 0;
    }
    if(s==2)
    {
        for(int i=0;i<=100;i++)
        {
            if(tabi[i]!=0)
            {
                tabo[a]=i;
                a++;
            }
        }
        if(tabi[tabo[0]]==tabi[tabo[1]])
        {
            cout<<"YES"<<endl<<tabo[0]<<" "<<tabo[1];
        }
        else
        {
            cout<<"NO";
            return 0;
        }
    }
	return 0;
}
