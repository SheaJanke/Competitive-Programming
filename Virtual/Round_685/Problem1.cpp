#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        if(n == 1){
            printf("0\n");
        }else if(n == 2){
            printf("1\n");
        }else if(n == 3 or n%2 == 0){
            printf("2\n");
        }else{
            printf("3\n");
        }
    }
}