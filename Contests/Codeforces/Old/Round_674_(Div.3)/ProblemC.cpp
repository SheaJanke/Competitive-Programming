#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        long long n;
        scanf("%lld", &n);
        long long x = 1;
        long long answer = (x-1) + (n + x - 1)/x - 1;
        x++;
        while((x-1) + (n + x - 1)/x - 1 <= answer){
            answer = (x-1) + (n + x - 1)/x - 1;
            x++;
        }
        printf("%lld\n", answer);
    }
}