#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    long long a,b,n,m;
    for(int i = 0; i < t; i++){
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
        if(a + b >= n + m and m <= min(a,b)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}