#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    queue<pair<int, int>> ones, twos;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i%2 == j%2){
                ones.push({i + 1, j + 1});
            }else{
                twos.push({i + 1, j + 1});
            }
        }
    }
    int val;
    for (int i = 0; i < n * n; i++)
    {
        cin >> val;
        if(val == 1){
            if(!twos.empty()){
                auto next = twos.front();
                twos.pop();
                cout << 2 << " " << next.first << " " << next.second << endl;
            }else{
                auto next = ones.front();
                ones.pop();
                cout << 3 << " " << next.first << " " << next.second << endl;
            }
        }else if(val == 2){
            if(!ones.empty()){
                auto next = ones.front();
                ones.pop();
                cout << 1 << " " << next.first << " " << next.second << endl;
            }else{
                auto next = twos.front();
                twos.pop();
                cout << 3 << " " << next.first << " " << next.second << endl;
            }
        }else{
            if(!ones.empty()){
                auto next = ones.front();
                ones.pop();
                cout << 1 << " " << next.first << " " << next.second << endl;
            }else{
                auto next = twos.front();
                twos.pop();
                cout << 2 << " " << next.first << " " << next.second << endl;
            }
        }
    }
    return 0;
}