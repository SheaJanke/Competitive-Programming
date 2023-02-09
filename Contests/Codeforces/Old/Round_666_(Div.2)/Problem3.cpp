#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    long long nums[n];
    for(int a = 0; a < n; a++){
        scanf("%lld", &nums[a]);
    }
    printf("1 1\n");
    printf("%lld\n", -nums[0]);
    nums[0] = 0;
    if(n == 1){
        printf("1 1\n0\n1 1\n0\n");
    }else{
        printf("2 %d\n", n);
        for(int a = 1; a < n; a++){
            printf("%lld ", (n-1) * nums[a]);
            nums[a] += (n-1) * nums[a];
        }
        printf("\n1 %d\n", n);
        for(int a = 0; a < n; a++){
            printf("%lld ", -nums[a]);
        }
        printf("\n");
    }
}