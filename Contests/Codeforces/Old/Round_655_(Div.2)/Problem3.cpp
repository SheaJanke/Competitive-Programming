#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        scanf("%d", &n);
        int num;
        bool lastMatch = true;
        int wrongSeq = 0;
        for(int b = 0; b < n; b++){
            scanf("%d", &num);
            if(num == b+1){
                lastMatch = true;
            }else{
                if(lastMatch){
                    wrongSeq++;
                    lastMatch = false;
                }
            }
        }
        if(wrongSeq == 0){
            printf("0\n");
        }else if(wrongSeq == 1){
            printf("1\n");
        }else{
            printf("2\n");
        }
    }
}