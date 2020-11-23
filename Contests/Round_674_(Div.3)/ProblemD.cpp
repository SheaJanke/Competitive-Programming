#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int answer = 0;
    long long curSum = 0, val;
    unordered_set<long long> sums;
    for(int b = 0; b < n; b++){
        scanf("%lld", &val);
        curSum += val;
        if(sums.find(curSum) != sums.end() or curSum == 0){
            answer++;
            sums = unordered_set<long long>();
            curSum = val;
        }
        sums.emplace(curSum);
    }
    printf("%d\n",answer);
}