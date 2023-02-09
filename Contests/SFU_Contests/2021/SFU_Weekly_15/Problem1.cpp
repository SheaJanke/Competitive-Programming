#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    long long cost[n];
    for(int a = 0; a < n; a++){
        scanf("%lld", &cost[a]);
    }
    sort(cost, cost + n);
    long long total = 0;
    for(int a = 0; a < n; a++){
        total += cost[n-1-a] * (1 + a/k);
    }
    printf("%lld\n",total);
}