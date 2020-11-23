#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, x;
        scanf("%d %d", &n ,&x);
        if(n <= 2){
            printf("1\n");
        }else{
            printf("%d\n", (n-3)/x + 2);
        }
        
    }
}