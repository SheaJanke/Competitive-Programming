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
        bool allSame = true;
        for(int b = 1; b < n; b++){
            if(nums[b] != nums[0]){
                allSame = false;
                break;
            }
        }
        if(allSame){
            printf("%d\n", n);
        }else{
            printf("%d\n", 1);
        }
    }
}