#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, a, b, c, d;
    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
    vector<int> squareSums;
    squareSums.push_back(a + b);
    squareSums.push_back(a + c);
    squareSums.push_back(c + d);
    squareSums.push_back(b + d);
    sort(squareSums.begin(), squareSums.end());
    int diff = squareSums[3] - squareSums[0];
    if(diff >= n){
        printf("0\n");
    }else{
        printf("%lld\n", (n-diff) * n);
    }
}