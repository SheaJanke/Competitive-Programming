#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int arr[n], locked[n], sum = 0;
        for(int a = 0; a < n; a++){
            scanf("%d", &arr[a]);
            sum += arr[a];
        }
        vector<int> movableNeg, movablePos;
        for(int a = 0; a < n; a++){
            scanf("%d", &locked[a]);
            if(locked[a] == 0){
                if(arr[a] < 0){
                    movableNeg.push_back(arr[a]);
                }else{
                    movablePos.push_back(arr[a]);
                }
            }
        }
        sort(movableNeg.begin(), movableNeg.end());
        sort(movablePos.begin(), movablePos.end());
        for(int a = 0; a < n; a++){
            if(locked[a] == 1){
                printf("%d ",arr[a]);
            }else{
                if(!movablePos.empty()){
                    printf("%d ", movablePos.back());
                    movablePos.pop_back();
                }else{
                    printf("%d ", movableNeg[0]);
                    movableNeg.erase(movableNeg.begin());
                }
            }
        }
        printf("\n");


    }
}