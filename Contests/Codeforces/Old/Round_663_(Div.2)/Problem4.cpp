#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    string matrix[n];
    for(int a = 0; a < n; a++){
        cin >> matrix[a];
    }
    if(n >= 4 and m >= 4){
        printf("-1\n");
    }else if(n == 1 or m == 1){
        printf("0\n");
    }else{
        int sums[n-1][m-1];
        for(int a = 0; a < n-1; a++){
            for(int b = 0; b < m-1; b++){
                sums[a][b] = 0;
                if(matrix[a][b] == '1'){
                    sums[a][b]++;
                }
                if(matrix[a][b+1] == '1'){
                    sums[a][b]++;
                }
                if(matrix[a+1][b] == '1'){
                    sums[a][b]++;
                }
                if(matrix[a][b] == '1'){
                    sums[a][b]++;
                }
            }
        }
        if(n == 2){

        }else if(m == 2){

        }else if(n == 3){

        }else if(m == 3){

        }
    }
}