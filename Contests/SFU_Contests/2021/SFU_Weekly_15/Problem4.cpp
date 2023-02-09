#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int l, b;
        scanf("%d %d", &l, &b);
        for(int i = min(l,b); i > 0; i--){
            if(l%i == 0 and b % i == 0){
                printf("%d\n", (l/i) * (b/i));
                break;
            }
        }
    }
}