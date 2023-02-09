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
    int answer[n];
    for(int a = 0; a < n; a++){
        if(a%2 == 0){
            answer[a] = nums[n-(a/2)-1];
        }else{
            if(n%2 == 0){
                if(a == n-1){
                    answer[a] = nums[(n/2)-1];
                }else{
                    answer[a] = nums[(n/2)-(a/2)-2];
                }
            }else{
                answer[a] = nums[(n/2)-(a/2)-1];
            }
        }
    }
    int total = 0;
    for(int a = 1; a < n-1; a++){
        if(answer[a] < answer[a-1] and answer[a] < answer[a+1]){
            total++;
        }
    }
    printf("%d\n", total);
    for(int a = 0; a < n; a++){
        printf("%d ", answer[a]);
    }
    printf("\n");
}