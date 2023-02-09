#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    long long x, y, n;
    for(int i = 0; i < t; i++){
        scanf("%lld %lld %lld", &x, &y, &n);
        long long rem = n%x;
        if(rem >= y){
            printf("%lld\n", n-rem+y);
        }else{
            printf("%lld\n", n-rem-x+y);
        }
    }
}