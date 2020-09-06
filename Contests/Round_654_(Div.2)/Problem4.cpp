#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        scanf("%d %d", &n, &k);
        int arr[n][n];
        for(int b = 0; b < n; b++){
            for(int c = 0; c < n; c++){
                arr[b][c] = 0;
            }
        }
        int currRow = 0, currCol = 0, count = 0;
        while(count < k){
            arr[currRow][currCol] = 1;
            if(currRow == n-1){
                currCol += 2;
            }else{
                currCol++;
            }
            currRow++;
            currRow = currRow%n;
            currCol = currCol%n;
            count++;
        }
        if(k%n == 0){
            printf("0\n");
        }else{
            printf("2\n");
        }
        for(int b = 0; b < n; b++){
            for(int c = 0; c < n; c++){
                printf("%d", arr[b][c]);
            }
            printf("\n");
        }


    }
}