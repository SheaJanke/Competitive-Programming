#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, a, b, c;
        scanf("%d %d %d %d", &n, &a, &b, &c);
        printf("Case #%d: ", i+1);
        if(c + (b-c) + (a-c) > n){
            printf("IMPOSSIBLE\n");
        }else{
            if(c == 1){
                bool left = false, right = false;
                if(a > 1){
                    left = true;
                }
                if(b > 1){
                    right = true;
                }
                if(left){
                    for(int j = 0; j < (a-c); j++){
                        printf("%d ", n-1);
                    }
                    for(int j = 0; j < n - c - (b-c) - (a-c); j++){
                        printf("1 ");
                    }
                    for(int j = 0; j < c; j++){
                        printf("%d ", n);
                    }
                    for(int j = 0; j < (b-c); j++){
                        printf("%d ", n-1);
                    }
                    printf("\n");
                }else if(right){
                    for(int j = 0; j < (a-c); j++){
                        printf("%d ", n-1);
                    }
                    for(int j = 0; j < c; j++){
                        printf("%d ", n);
                    }
                    for(int j = 0; j < n - c - (b-c) - (a-c); j++){
                        printf("1 ");
                    }
                    for(int j = 0; j < (b-c); j++){
                        printf("%d ", n-1);
                    }
                    printf("\n");
                }else if(n==1){
                    printf("1\n");
                }else{
                    printf("IMPOSSIBLE\n");
                }
            }else{
                for(int j = 0; j < (a-c); j++){
                    printf("%d ", n-1);
                }
                printf("%d ", n);
                for(int j = 0; j < n - c - (b-c) - (a-c); j++){
                    printf("1 ");
                }
                for(int j = 0; j < c-1; j++){
                    printf("%d ", n);
                }
                for(int j = 0; j < (b-c); j++){
                    printf("%d ", n-1);
                }
                printf("\n");
            }
            
        }

    }
}