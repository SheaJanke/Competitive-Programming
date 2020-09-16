#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        long long x, y, k;
        scanf("%lld %lld %lld", &x, &y, &k);
        printf("%lld\n", k + (y * k + x - 3)/(x-1));
    }
}