#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        int nums[n];
        for(int b = 0; b < n; b++){
            scanf("%d", &nums[b]);
        }
        long long answer = 0;
        for(int b = n-1; b > 0; b--){
            if(nums[b] < nums[b-1]){
                answer += nums[b-1] - nums[b];
            }
        }
        printf("%lld\n", answer);
    }
}