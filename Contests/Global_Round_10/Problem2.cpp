#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        long long k;
        scanf("%d %lld", &n, &k);
        long long nums[n];
        for(int b = 0; b < n; b++){
            scanf("%lld", &nums[b]);
        }
        long long maximum = nums[0], minimum = nums[0];
        for(int b = 1; b < n; b++){
            maximum = max(maximum, nums[b]);
            minimum = min(minimum, nums[b]);
        }
        for(int b = 0; b < n; b++){
            if(k%2 == 0){
                printf("%lld ", nums[b]-minimum);
            }else{
                printf("%lld ", maximum-nums[b]);
            }
        }
        printf("\n");
    }
}