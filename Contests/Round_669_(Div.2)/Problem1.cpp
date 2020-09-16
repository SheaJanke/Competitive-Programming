#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, num;
        int zeros = 0, ones = 0;
        scanf("%d", &n);
        for(int a = 0; a < n; a++){
            scanf("%d", &num);
            if(num == 0){
                zeros++;
            }else{
                ones++;
            }
        }
        if(zeros >= n/2){
            printf("%d\n", n/2);
            for(int a = 0; a < n/2; a++){
                printf("0 ");
            }
        }else{
            if(n%4 == 0){
                printf("%d\n", n/2);
                for(int a = 0; a < n/2; a++){
                    printf("1 ");
                }
            }else{
                printf("%d\n", n/2 + 1);
                for(int a = 0; a < n/2 + 1; a++){
                    printf("1 ");
                }
            }
        }
        printf("\n");
    }
}