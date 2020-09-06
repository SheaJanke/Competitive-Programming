#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long n;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        scanf("%lld", &n);
        if(n%2 == 0){
            printf("%lld %lld\n",n/2, n/2);
        }else{
            int divisor = 1;
            for(int b = 2; b <= sqrt(n); b++){
                if(n%b == 0){
                    divisor = b;
                    break;
                }
            }
            if(divisor == 1){
                printf("%d %lld\n", 1, n-1);
            }else{
                printf("%lld %lld\n", n/divisor, n-(n/divisor));
            }
        }
    }
}