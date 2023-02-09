#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);
    long long answer = 1, subtract = 1;
    for(long long b = 2; b <= n; b++){
        answer *= b;
        subtract *= 2;
        answer %= (long long)1000000007;
        subtract %= (long long)1000000007;
    }
    answer -= subtract;
    if(answer < 0){
        answer += (long long)1000000007;
    }
    printf("%lld\n", answer);
}