#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        long long x1, x2, x3;
        scanf("%lld %lld %lld", &x1, &x2, &x3);
        printf("%lld\n", x1 + x2 + x3 -1);
    }
}