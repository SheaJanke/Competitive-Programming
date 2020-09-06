#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    multiset<pair<int,int>> test;
    test.emplace(make_pair(15, 10));
    test.emplace(make_pair(10, 10));
    for(auto it = test.begin(); it != test.end(); it++){
        printf("%d %d\n", it->first, it->second);
    }

    for(int a = 0; a < t; a++){
        int answer = 0;



        printf("Case #%d: %d\n", a+1, answer);
    }
}