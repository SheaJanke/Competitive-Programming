#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, k;
        scanf("%d %d", &n, &k);
        int val = n-k;
        if(val < 0){
            printf("%d\n", -val);
        }else if(val%2 == 0){
            printf("0\n");
        }else{
            printf("1\n");
        }
    }
}