#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, x;
        scanf("%d %d", &n, &x);
        int num;
        bool allSame = true;
        bool hasOneSame = false;
        int diff = 0;
        for(int a = 0; a < n; a++){
            scanf("%d", &num);
            if(num != x){
                allSame = false;
            }else{
                hasOneSame = true;
            }
            diff += (x-num);
        }
        if(allSame){
            printf("0\n");
        }else if(diff == 0){
            printf("1\n");
        }else{
            if(hasOneSame){
                printf("1\n");
            }else{
                printf("2\n");
            }
        }
        
    }
}