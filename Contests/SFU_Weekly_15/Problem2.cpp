#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int r, c;
        scanf("%d %d", &r, &c);
        string grid[r];
        for(int i = 0; i < r; i++){
            cin >> grid[i];
        }
        int cost[r][c];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cost[i][j] = pow(10,8);
            }
        }
        cost[0][0] = 0;
        deque<pair<int,int>> coords;
        coords.push_front(make_pair(0,0));
        while (!coords.empty()){
            int x = coords.front().first, y = coords.front().second;
            coords.pop_front();
            int add = 0;
            if(x > 0){
                if(grid[x-1][y] != grid[x][y]){
                    add = 1;
                }else{
                    add = 0;
                }
                if(cost[x][y] + add < cost[x-1][y]){
                    cost[x-1][y] = cost[x][y] + add;
                    if(add == 1){
                        coords.push_back(make_pair(x-1, y));
                    }else{
                        coords.push_front(make_pair(x-1, y));
                    }
                }
            }
            if(y > 0){
                if(grid[x][y-1] != grid[x][y]){
                    add = 1;
                }else{
                    add = 0;
                }
                if(cost[x][y] + add < cost[x][y-1]){
                    cost[x][y-1] = cost[x][y] + add;
                    if(add == 1){
                        coords.push_back(make_pair(x, y-1));
                    }else{
                        coords.push_front(make_pair(x, y-1));
                    }
                }
            }
            if(x < r-1){
                if(grid[x+1][y] != grid[x][y]){
                    add = 1;
                }else{
                    add = 0;
                }
                if(cost[x][y] + add < cost[x+1][y]){
                    cost[x+1][y] = cost[x][y] + add;
                    if(add == 1){
                        coords.push_back(make_pair(x+1, y));
                    }else{
                        coords.push_front(make_pair(x+1, y));
                    }
                }
            }
            if(y < c-1){
                if(grid[x][y+1] != grid[x][y]){
                    add = 1;
                }else{
                    add = 0;
                }
                if(cost[x][y] + add < cost[x][y+1]){
                    cost[x][y+1] = cost[x][y] + add;
                    if(add == 1){
                        coords.push_back(make_pair(x, y+1));
                    }else{
                        coords.push_front(make_pair(x, y+1));
                    }
                }
            }
        }
        printf("%d\n", cost[r-1][c-1]);
    }
}