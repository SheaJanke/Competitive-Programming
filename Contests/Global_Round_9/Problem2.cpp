#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        scanf("%d %d", &n, &m);
        int arr[n][m];
        bool works = true;
        for(int b = 0; b < n; b++){
            for(int c = 0; c < m; c++){
                scanf("%d", &arr[b][c]);
                int count = 0;
                if(b == 0 or b == n-1){
                    count++;
                }
                if(c == 0 or c == m-1){
                    count++;
                }
                if(arr[b][c] > 4-count){
                    works = false;
                }else{
                    arr[b][c] = 4-count;
                }
            }
        }
        if(works){
            printf("YES\n");
            for(int b = 0; b < n; b++){
                for(int c = 0; c < m; c++){
                    printf("%d ", arr[b][c]);
                }
                printf("\n");
            }
        }else{
            printf("NO\n");
        }
    }
}