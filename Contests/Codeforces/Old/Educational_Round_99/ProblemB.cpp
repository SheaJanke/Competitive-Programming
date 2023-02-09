#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; k++){
        int x;
        scanf("%d", &x);
        int jumps = 0;
        int total = 0;
        while(total < x){
            jumps++;
            total += jumps;
        }
        if(total-1 == x){
            printf("%d\n", jumps+1);
        }else{
            printf("%d\n", jumps);
        }
    }
}