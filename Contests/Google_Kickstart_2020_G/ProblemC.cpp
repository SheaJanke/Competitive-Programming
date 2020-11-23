#include <bits/stdc++.h>
using namespace std;

long long calculateScore(long long target, long long arr[], long long w, long long n){
    long long total = 0;
    for(int b = 0; b < w; b++){
        long long curMin = min(abs(arr[b]-target), abs(arr[b]-(target+n)));
        total += min(curMin, abs(arr[b]-(target-n)));
    }
    return total;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        long long n, w;
        scanf("%lld %lld", &w, &n);
        long long arr[w];
        for(int a = 0; a < w; a++){
            scanf("%lld", &arr[a]);
        }
        sort(arr, arr+w);
        long long total = arr[0];
        for(int a = 1; a < w; a++){
            if(abs(total/a - arr[a]) < abs(total/a - (arr[a]-n))){
                total += arr[a];
            }else{
                total += (arr[a]-n);
            }
        }
        long long target = (long long)round(((double)total)/w);
        long long answer = calculateScore(target, arr, w, n);
        
        printf("Case #%d: %lld\n", i+1, answer);
    }
}