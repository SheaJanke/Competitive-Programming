#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    scanf("%lld", &n);
    long long arr[n];
    long long total = 0;
    for(int a = 0; a < n; a++){
        scanf("%lld", &arr[a]);
        total += arr[a];
    }
    int remove = (n-1)/2;
    if(remove == 0){
        printf("%lld\n", total);
    }else{
        int startIndex = 0, endIndex = 2 * (remove-1);
        long long subtotal = 0;
        for(int a = 0; a <= endIndex; a+=2){
            subtotal += arr[a];
        }
        long long minSubtotal = subtotal;
        startIndex = (startIndex + 2)%n;
        subtotal -= arr[0];
        endIndex = (endIndex + 2)%n;
        while(startIndex != 0){
            subtotal += arr[endIndex];
            endIndex = (endIndex + 2)%n;
            minSubtotal = min(subtotal, minSubtotal);
            subtotal -= arr[startIndex];
            startIndex = (startIndex + 2)%n;
        }
        printf("%lld\n", total-minSubtotal);
    }
}