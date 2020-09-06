#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n; 
        scanf("%d", &n);
        int arr[n];
        long long cur = 0, maximum = 0;
        for(int a = 0; a < n; a++){
            scanf("%d", &arr[a]);
            cur -= arr[a];
            maximum = max(maximum, cur);
        }
        printf("%lld\n", maximum);
    }
}