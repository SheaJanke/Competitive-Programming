#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int start, int end){
    for(int i = start; i < end; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}


int main(){
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; k++){
        int n, x;
        scanf("%d %d", &n, &x);
        int arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        int changes = 0;
        int possible = true;
        int i = 0;
        while(i < n){
            if(i > 0 and arr[i] < arr[i-1]){
                possible = false;
                break;
            }
            if(!isSorted(arr,i,n-1)){
                if(arr[i] > x){
                    changes++;
                    int temp = x;
                    x = arr[i];
                    arr[i] = temp;
                }
                i++;
            }else{
                break;
            }
        }
        if(possible){
            printf("%d\n", changes);
        }else{
            printf("-1\n");
        }
    }
}