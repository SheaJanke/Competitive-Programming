#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int c, d;
        scanf("%d %d", &c, &d);
        if((c-d)%2 == 0){
            if(c==d){
                if(c == 0){
                    printf("0\n");
                }else{
                    printf("1\n");
                }
            }else{
                printf("2\n");
            }
        }else{
            printf("-1\n");
        }
    }
}