#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    long long grid[25][25] = {0};
    
    for(int a = 1; a < 25; a+=2){
        for(int b = 0; b < 25; b++){
            grid[a][b] = pow(2, a + b - 1);
        }
    }
    
    int n, t;
    cin >> n;
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            cout << grid[a][b] << " ";
        }
        cout << endl;
    }
    cout << flush;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long val;
        cin >> val;
        int curX = 0, curY = 0;
        cout << "1 1 ";
        while(!(curX == n-1 and curY == n-1)){
            if(curY%2 == 0){
                if(val%2 != 0){
                    curY++;
                }else{
                    curX++;
                }
            }else{
                if(val%2 != 0){
                    curX++;
                }else{
                    curY++;
                }
            }
            cout << curX+1 << " " << curY+1 << " ";
            val = val >> 1;
        }
        cout << endl << flush;
    }
}