#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int nums[n];
    for(int a = 0; a < n; a++){
        scanf("%d", &nums[a]);
    }
    sort(nums, nums + n);
    printf("%d\n", (n-1)/2);
    int left = 0, right = n-1;
    int index = 0;
    while(left <= right){
        if(index%2 == 0){
            printf("%d ", nums[right]);
            right--;
        }else{
            printf("%d ", nums[left]);
            left++;
        }
        index++;
    }
}