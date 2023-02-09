#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int groups[n][m];
    int relColSum[m];
    for(int a = 0; a < n; a++){
        int intervals, start, end;
        scanf("%d", &intervals);
        for(int b = 0; b < intervals; b++){
            scanf("%d %d", &start, &end);
            for(int c = start; c <= end; c++){
                groups[a][c-1] = b;
            }
        }
    }
    for(int a = 0; a < m; a++){
        relColSum[a] = 0;
    }
    int answer[n][m];
    for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            if(b == 0){
                answer[a][b] = 1;
            }else if(b == m-1 and groups[a][0] != groups[a][b]){
                answer[a][b] = 1;
            }else{
                answer[a][b] = 0;
            }
        }
    }
    for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            if(groups[a][b] == 0 or groups[a][b] == groups[a][m-1]){
                relColSum[b]--;
                groups[a][b] = -1;
            }
        }
    }
}