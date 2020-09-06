#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k, actual;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        scanf("%d %d", &n, &k);
        int nums[n];
        for(int b = 0; b < n; b++){
            scanf("%d", &actual);
            if(actual%k == 0){
                nums[b] = 0;
            }else{
                nums[b] = k-(actual%k);
            }
        }
        sort(nums, nums+n);
        long long longest = 1, current = 1, longestNum = nums[0], currentNum = nums[0];
        for(int b = 1; b < n; b++){
            if(nums[b] == currentNum){
                current++;
            }else{
                current = 1;
                currentNum = nums[b];
            }
            if(current >= longest and currentNum != 0){
                longest = current;
                longestNum = currentNum;
            }
        }
        if(longestNum == 0){
            printf("0\n");
        }else{
            printf("%lld\n", (longest-1)*k + longestNum + 1);
        }
    }
}