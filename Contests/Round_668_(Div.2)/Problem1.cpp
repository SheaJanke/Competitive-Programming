#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int a = 0; a < n; a++){
            scanf("%d", &arr[a]);
        }
        for(int a = n-1; a >= 0; a--){
            printf("%d ", arr[a]);
        }
        printf("\n");
    }
}