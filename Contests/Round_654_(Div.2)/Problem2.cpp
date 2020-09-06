#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    long long n, r;
    for(int a = 0; a < t; a++){
        scanf("%lld %lld", &n, &r);
        long long b = min(n-1, r);
        long long total = (b * (b+1))/2;
        if(r >= n){
            total++;
        }
        printf("%lld\n", total);
    }
}