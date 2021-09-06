#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
        long long r, b, d;
        scanf("%lld %lld %lld", &r, &b, &d);
        long long maxi = max(r, b);
        long mini = min(r, b);
        maxi -= (mini * (d + 1));
        if(maxi > 0){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
}