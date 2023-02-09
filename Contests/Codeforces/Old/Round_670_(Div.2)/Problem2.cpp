#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        long long arr[n];
        for(int a = 0; a < n; a++){
            scanf("%lld", &arr[a]);
        }
        sort(arr, arr+n);
        long long maximum = 1;
        maximum = arr[n-1] * arr[n-2] * arr[n-3] * arr[n-4] * arr[n-5];
        maximum = max(maximum, arr[0] * arr[1] * arr[n-1] * arr[n-2] * arr[n-3]);
        maximum = max(maximum, arr[0] * arr[1] * arr[n-1] * arr[2] * arr[3]);
        printf("%lld\n", maximum);

    }
}