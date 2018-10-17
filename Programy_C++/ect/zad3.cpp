#include <bits/stdc++.h>
using namespace std;
int tab[10000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    int odl;
    int tabi[1];
    odl=abs(tab[0]-tab[1]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(odl>tab[i]-tab[j])
            {
                odl=abs(tab[i]-tab[j]);
                tabi[0]=tab[i], tabi[1]=tab[j];
            }
        }
    }
    cout<<tabi[0]<<" "<<tabi[1];
	return 0;
}
