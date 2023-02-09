#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        long long n, answer = 0;
        scanf("%lld", &n);
        answer = (n * (n+1))/2;
        long long power = 1;
        while(power <= n){
            power *= 2;
        }
        printf("%lld\n", answer-(power-1)*2);
    }
}