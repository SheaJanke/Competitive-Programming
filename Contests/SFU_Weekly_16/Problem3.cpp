#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int _ = 0; _ < t; _++){
        map<string, vector<int>> scoreboard;
        string t1, t2, vs;
        int g1, g2;
        for(int a = 0; a < 12; a++){
            cin >> t1 >> g1 >> vs >> g2 >> t2;
            int t1Points, t2Points;
            if(g1 > g2){
                t1Points = 3;
                t2Points = 0;
            }else if(g1 < g2){
                t1Points = 0;
                t2Points = 3;
            }else{
                t1Points = 1;
                t2Points = 1;
            }
            vector<int> t1Add = {t1Points, g1-g2}, t2Add = {t2Points, g2-g1};
            if(scoreboard.find(t1) != scoreboard.end()){
                scoreboard[t1][0] += t1Add[0];
                scoreboard[t1][1] += t1Add[1];
            }else{
                scoreboard[t1] = t1Add;
            }
            if(scoreboard.find(t2) != scoreboard.end()){
                scoreboard[t2][0] += t2Add[0];
                scoreboard[t2][1] += t2Add[1];
            }else{
                scoreboard[t2] = t2Add;
            }
        }
        vector<tuple<int,int,string>> leaderboard;
        for(auto it = scoreboard.begin(); it != scoreboard.end(); it++){
            leaderboard.push_back(make_tuple(it->second[0], it->second[1], it->first));
        }
        sort(leaderboard.begin(), leaderboard.end());
        cout << get<2>(leaderboard[3]) << " " << get<2>(leaderboard[2]) << endl;
    }
}