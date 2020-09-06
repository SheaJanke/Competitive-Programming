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
        if(arr[0] < arr[n-1]){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}