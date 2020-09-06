#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int b = 0; b < n; b++){
            scanf("%d", &arr[b]);
        }
        int arr2[n];
        copy(arr, arr + n, arr2);
        sort(arr2, arr2 + n);
        bool works = true;
        for(int b = 0; b < n; b++){
            if(arr[b] != arr2[b] and arr[b] % arr2[0] != 0){
                works = false;
                break;
            }
        }
        if(works){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}