#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    scanf("%d %d", &n, &p);
    int nums[n];
    for(int a = 0; a < n; a++){
        scanf("%d", &nums[a]);
    }
    sort(nums, nums+n);
    int start = nums[0];
    for(int a = 0; a < n; a++){
        start = max(start, nums[a] - a);
    }
    int end = nums[p-1];
    for(int a = p; a < n; a++){
        end = min(end, nums[a]-(a-p+1));
    }
    printf("%d\n", max(end-start,0));
    for(int a = start; a < end; a++){
        printf("%d ", a);
    }
    printf("\n");
}