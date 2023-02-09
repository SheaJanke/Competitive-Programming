#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        long long answer = 0;
        int n;
        scanf("%d", &n);
        long long x[n], y[n];
        for(int j = 0; j < n; j++){
            scanf("%lld %lld", &x[j], &y[j]);
        }
        sort(x, x+n);
        sort(y, y+n);
        long long midy = y[n/2];
        for(int j = 0; j < n; j++){
            answer += abs(midy-y[j]);
        }
        long long add = pow(10,18);
        for(int j = -500; j <= 500; j++){
            long long curAdd = 0;
            for(int k = 0; k < n; k++){
                curAdd += abs(j + k - x[k]);
            }
            add = min(curAdd, add);
        }
        printf("Case #%d: %lld\n", i+1, answer + add);
    }
}