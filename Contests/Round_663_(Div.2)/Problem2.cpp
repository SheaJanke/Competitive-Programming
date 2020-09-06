#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n,m;
        scanf("%d %d", &n, &m);
        string path[n];
        for(int b = 0; b < n; b++){
            cin >> path[b];
        }
        int replace = 0;
        for(int c = 0; c < m-1; c++){
            if(path[n-1][c] != 'R'){
                replace++;
            }
        }
        for(int c = 0; c < n-1; c++){
            if(path[c][m-1] != 'D'){
                replace++;
            }
        }
        printf("%d\n", replace);
    }
}