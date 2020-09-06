#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        long long a,b,x,y,n;
        scanf("%lld %lld %lld %lld %lld", &a, &b, &x, &y, &n);
        long long A = max(a-n, x), B = max(b-n,y);
        if(A<B){
            printf("%lld\n", A * max(b-(n-(a-A)), y));
        }else{
            printf("%lld\n", B * max(a-(n-(b-B)), x));
        }
    }
}