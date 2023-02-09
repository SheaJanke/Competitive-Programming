#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        long long N,S,K;
        scanf("%lld %lld %lld", &N, &S, &K);
        printf("Case #%d: %lld\n", i+1, min(2*(S-K), S) + N);
    }
}