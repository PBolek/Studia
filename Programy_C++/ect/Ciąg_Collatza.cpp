#include <bits/stdc++.h>
#include <stdio.h>
#include <limits>
using namespace std;
long long int ai,maxai,pozostalo;
long long int l=0;
int main()
{
    cin>>ai;
    maxai=pozostalo=ai;
    while(ai>1)
    {
        if(ai%2==0)
        {
            ai=ai/2;
        }
        else if(ai<=((ULLONG_MAX-1)/3))
        {
            ai=3*(ai)+1;
        }
        else
        {
            printf("Blad - przekroczenie mozliwego zakresu\n");
            return 1;
        }
        if(ai>maxai)
        {
            maxai=pozostalo=ai;
        }
        pozostalo--;
        if(pozostalo==0)
        {
            printf("Blad - program sie zapetla");
            return 2;
        }
        l++;
    }
    cout<<l;
	return 0;
}
