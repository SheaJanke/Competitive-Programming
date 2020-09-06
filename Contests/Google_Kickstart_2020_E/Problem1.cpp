#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int answer = 0;
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int b = 0; b < n; b++){
            scanf("%d", &arr[b]);
        }
        int streak = 2, diff = arr[1] - arr[0];
        for(int b = 2; b < n; b++){
            if(arr[b] - arr[b-1] == diff){
                streak++;
            }else{
                answer = max(answer, streak);
                streak = 2;
                diff = arr[b] - arr[b-1];
            }
        }
        answer = max(answer, streak);
        printf("Case #%d: %d\n", a+1, answer);
    }
}