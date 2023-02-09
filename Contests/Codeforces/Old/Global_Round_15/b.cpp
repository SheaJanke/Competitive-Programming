#include <bits/stdc++.h>
using namespace std;

bool wins(vector<int> &p1, vector<int> &p2){
    int winCount = 0;
    for (int i = 0; i < 5; i++){
        if(p1[i] < p2[i]){
            winCount++;
        }
    }
    return winCount > 2;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        vector<vector<int>> vals(n, vector<int>(5));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 5; j++){
                int val;
                scanf("%d", &vals[i][j]);
            
            }
        }
        int winning = 0;
        for (int i = 1; i < n; i++){
            if(wins(vals[i], vals[winning])){
                winning = i;
            }
        }
        bool isWinner = true;
        for (int i = 0; i < n; i++){
            if(i != winning){
                if(!wins(vals[winning], vals[i])){
                    isWinner = false;
                }
            }
        }
        if(isWinner){
            printf("%d\n", winning + 1);
        }else{
            printf("-1\n");
        }
    }
}