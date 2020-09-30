#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int a = 0; a < n; a++){
        scanf("%d", &arr[a]);
    }
    sort(arr, arr + n);
    int l = 0, r = n-1;
    for(int a = 0; a < n; a++){
        if(a%2 == 0){
            printf("%d ", arr[l]);
            l++;
        }else{
            printf("%d ", arr[r]);
            r--;
        }
    }
    printf("\n");
}