#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    long long n,x;
    for(int a = 0; a < t; a++){
        scanf("%lld %lld", &n, &x);
        long long arr[n];
        for(int b = 0; b < n; b++){
            scanf("%lld", &arr[b]);
        }
        sort(arr, arr+n);
        int teams = 0;
        int onTeam = 0;
        for(int b = n-1; b >= 0; b--){
            onTeam++;
            if(onTeam * arr[b] >= x){
                onTeam = 0;
                teams++;
            }
        }
        printf("%d\n", teams);
    }

}