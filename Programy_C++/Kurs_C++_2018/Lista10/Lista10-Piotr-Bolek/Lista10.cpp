#include <bits/stdc++.h>
#include <iostream>
#include "Lista10.h"

using namespace std;
namespace strumienie
{
istream& clearline(istream& stream)
{
    char s;
    cin.get(s);
    while(s != '\n')
    {
        cin.get(s);
    }
    return stream;
}

ostream& comma (ostream& stream)
{
    return stream<<", ";
}

ostream& colon (ostream& stream)
{
    return stream<<": ";
}
}



