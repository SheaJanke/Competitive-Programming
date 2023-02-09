#include <bits/stdc++.h>
using namespace std;

int main(){
    set<pair<int, int>> test;
    test.emplace(make_pair(1,2));
    test.emplace(make_pair(1,2));
    for(auto it = test.begin(); it != test.end(); it++){
        printf("%d %d\n", it->first, it->second);
    }
}