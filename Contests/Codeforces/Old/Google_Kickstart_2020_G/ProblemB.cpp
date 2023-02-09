#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int arr[n][n];
        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){
                scanf("%d", &arr[a][b]);
            }
        }
        long long maximum = 0;
        for(int j = 0; j < n; j++){
            int row = 0, col = j;
            long long cur = 0;
            while(col < n and row < n){
                cur += arr[row][col];
                row++;
                col++;
            }
            maximum = max(maximum, cur);
        }
        for(int j = 1; j < n; j++){
            int col = 0, row=j;
            long long cur = 0;
            while(col < n and row < n){
                cur += arr[row][col];
                row++;
                col++;
            }
            maximum = max(maximum, cur);
        }
        printf("Case #%d: %lld\n", i+1, maximum);
    }
}