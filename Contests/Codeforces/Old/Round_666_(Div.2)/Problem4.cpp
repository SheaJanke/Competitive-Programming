#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        int nums[n];
        int maximum = 0, total = 0;
        for(int b = 0; b < n; b++){
            scanf("%d", &nums[b]);
            maximum = max(nums[b], maximum);
            total += nums[b];
        }
        if(maximum > total/2){
            printf("T\n");
        }else if(total%2 ==1){
            printf("T\n");
        }else{
            printf("HL\n");
        }
    }
}