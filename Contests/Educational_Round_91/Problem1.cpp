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
        bool works = false;
        for(int b = 0; b < n-2; b++){
            if(arr[b] < arr[b+1] and arr[b+1] > arr[b+2]){
                printf("Yes\n");
                printf("%d %d %d\n", b+1, b+2, b+3);
                works = true;
                break;
            }
        }
        if(!works){
            printf("No\n");
        }
    }
}