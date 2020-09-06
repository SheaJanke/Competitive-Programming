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
        if(n < 3){
            printf("0\n");
        }else{
            int curIndex = n-2;
            while(curIndex >= 0 and nums[curIndex] >= nums[curIndex+1]){
                curIndex--;
            }
            while(curIndex >= 0 and nums[curIndex] <= nums[curIndex+1]){
                curIndex--;
            }
            printf("%d\n", curIndex+1);
        }
    }
}