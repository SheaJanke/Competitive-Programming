#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        int n, k;
        scanf("%d %d", &n, &k);
        int arr[n];
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        bool worksLeftToRight = true;
        int curMin = arr[0], curMax = arr[0];
        for (int j = 0; j < n-1; j++)
        {
            if(curMin - k + 1 > arr[j+1] + k - 1){
                worksLeftToRight = false;
                break;
            }
            if(curMax + k - 1 < arr[j+1]){
                worksLeftToRight = false;
                break;
            }
            curMin = max(arr[j + 1], curMin - k + 1);
            curMax = min(arr[j + 1] + k - 1, curMax + k - 1);
        }
        bool worksRightToLeft = true;
        curMin = arr[n - 1];
        curMax = arr[n - 1];
        for (int j = n - 1; j > 0; j--){
            if(curMin - k + 1 > arr[j-1] + k - 1){
                worksRightToLeft = false;
                break;
            }
            if(curMax + k - 1 < arr[j-1]){
                worksRightToLeft = false;
                break;
            }
            curMin = max(arr[j - 1], curMin - k + 1);
            curMax = min(arr[j - 1] + k - 1, curMax + k - 1);
        }
        if(worksRightToLeft && worksLeftToRight){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}