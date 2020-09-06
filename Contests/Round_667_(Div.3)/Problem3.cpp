#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, x, y;
        scanf("%d %d %d", &n, &x, &y);
        int diff = y-x;
        int step = diff;
        for(int b = n-1; b > 0; b--){
            if(diff % b == 0){
                step = diff/b;
                break;
            }
        }
        int nums = 0;
        while(nums < n and y-(step*nums) > 0){
            printf("%d ", y-(step*nums));
            nums++;
        }
        for(int b = nums; b < n; b++){
            printf("%d ", y + (b-nums+1) * step);
        }
        printf("\n");
    }
}