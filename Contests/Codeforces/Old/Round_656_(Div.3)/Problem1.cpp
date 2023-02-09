#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int nums[3];
        scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);
        sort(nums, nums + 3);
        if(nums[1] != nums[2]){
            printf("NO\n");
        }else{
            printf("YES\n");
            printf("%d %d %d\n", nums[2], nums[0], 1);
        }
    }
}