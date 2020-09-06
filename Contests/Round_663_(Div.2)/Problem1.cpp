#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        for(int b = n; b > 0; b--){
            printf("%d ", b);
        }
        printf("\n");
    }
}