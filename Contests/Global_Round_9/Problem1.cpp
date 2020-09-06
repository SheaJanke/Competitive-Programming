#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        scanf("%d", &n);
        int arr[n];
        for(int b = 0; b < n; b++){
            scanf("%d", &arr[b]);
        }
        for(int b = 0; b < n; b++){
            if(b%2 == 0 and arr[b] < 0){
                arr[b] = -arr[b];
            }else if(b%2 == 1 and arr[b] > 0){
                arr[b] = -arr[b];
            }
            printf("%d ", arr[b]);
        }
        printf("\n");
    }
}