#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, k, answer = 0;
        scanf("%d %d", &n, &k);
        int arr[n];
        for(int b = 0; b < n; b++){
            scanf("%d", &arr[b]);
        }
        sort(arr, arr + n);
        for(int b = 1; b < n; b++){
            if(arr[b] < k){
                answer += (k-arr[b])/arr[0];
            }
        }
        printf("%d\n", answer);
    }
}