#include <bits/stdc++.h>
using namespace std;

/*
bool valid(int vals[][m], bool** changed, int n, int m, int j, int k, int newVal){
    if(changed[j][k]){
        return false;
    }
    if(j > 0 and vals[j-1][k] == newVal){
        return false;
    }
    if(k > 0 and vals[j][k-1] == newVal){
        return false;
    }
    return true;
}
*/

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, m;
        scanf("%d %d", &n, &m);
        int vals[n][m];
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                scanf("%d", &vals[j][k]);
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if((j+k)%2 != vals[j][k]%2){
                    vals[j][k]++;
                }
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                printf("%d ", vals[j][k]);
            }
            printf("\n");
        }
    }
}