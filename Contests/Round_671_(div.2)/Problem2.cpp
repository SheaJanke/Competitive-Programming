#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> stairs;
    stairs.push_back(1);
    int i = 1;
    while(2 * stairs[stairs.size()-1] + pow(pow(2,i),2) < pow(10,18)){
        stairs.push_back(2 * stairs[stairs.size()-1] + pow(pow(2,i),2));
        i++;
    }
    int t;
    scanf("%d", &t);
    for(int j = 0; j < t; j++){
        long long n;
        scanf("%lld", &n);
        int answer = 0;
        while(answer < stairs.size() and stairs[answer] <= n){
            n -= stairs[answer];
            answer++;
        }
        printf("%d\n", answer);
    }
}