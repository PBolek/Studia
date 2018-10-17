#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include "Lista10.h"

using namespace strumienie;

int main(){
    std::string s;
    std::vector<pair<std::string, int>> test;
    std::string helper;
    int counter = 0;
    while(!cin.eof()){
        getline(std::cin, helper);
        counter++;
        test.push_back(make_pair(helper, counter));
    }
    sort(test.begin(), test.end());
    for(int i = 1; i < counter; i++){
        cout<<index(test[i].second, 3)<<colon<<test[i].first<<comma;
    }

    return 0;
}
