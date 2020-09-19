#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, bEvens = 0, rOdds = 0;
        scanf("%d", &n);
        string num;
        cin >> num;
        for(int a = 0; a < n; a++){
            if(n%2 == 0 and (a+1)%2 == 0){
                if(((int)num[a] - 48)%2 == 0){
                    bEvens++;
                }
            }
            if(n%2 == 1 and (a+1)%2 == 1){
                if(((int)num[a] - 48)%2 == 1){
                    rOdds++;
                }
            }
        }
        if(n%2 == 0){
            if(bEvens > 0){
                printf("2\n");
            }else{
                printf("1\n");
            }
        }else{
            if(rOdds > 0){
                printf("1\n");
            }else{
                printf("2\n");
            }
        }
    }
}