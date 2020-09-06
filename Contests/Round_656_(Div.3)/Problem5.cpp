#include <bits/stdc++.h>
using namespace std;

void update_canReach(unordered_set<int> canReach[], unordered_set<int> reachedBy[], int src, int dst, int n){
    for(auto it = reachedBy[src].begin(); it != reachedBy[src].end(); it++){
        int a = *it;
        canReach[a].insert(canReach[dst].begin(), canReach[dst].end());
        canReach[a].insert(dst);
        reachedBy[dst].insert(a);
    }
    /*
    for(int a = 1; a <= n; a++){
        if(canReach[a].find(src) != canReach[a].end()){
            canReach[a].insert(canReach[dst].begin(), canReach[dst].end());
            canReach[a].insert(dst);
        }
    }
    */
    canReach[src].insert(canReach[dst].begin(), canReach[dst].end());
    reachedBy[dst].insert(reachedBy[src].begin(), reachedBy[src].end());
    canReach[src].insert(dst);
    reachedBy[dst].insert(src);

}

bool will_work(unordered_set<int> canReach[], unordered_set<int> reachedBy[], int src, int dst, int n){
    for(auto it = reachedBy[src].begin(); it != reachedBy[src].end(); it++){
        int a = *it;
        if(canReach[dst].find(a) != canReach[dst].end()){
            return false;
        }
    }
    /*
    for(int a = 1; a <= n; a++){
        if(canReach[a].find(src) != canReach[a].end()){
            if(canReach[dst].find(a) != canReach[dst].end()){
                return false;
            }
        }
    }
    */
    if(canReach[dst].find(src) != canReach[dst].end()){
        return false;
    }
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, m;
        scanf("%d %d", &n, &m);
        vector<pair<int,int>> answer, undirected;
        unordered_set<int> canReach[n+1], reachedBy[n+1];
        for(int b = 0; b < m; b++){
            int dir, src, dst;
            scanf("%d %d %d", &dir, &src, &dst);
            if(dir == 0){
                undirected.push_back(make_pair(src, dst));
            }else{
                answer.push_back(make_pair(src, dst));
                update_canReach(canReach, reachedBy, src, dst, n);
            }
        }
        bool works = true;
        for(int b = 1; b <= n; b++){
            if(canReach[b].find(b) != canReach[b].end()){
                works = false;
            }
        }

        for(int b = 0; b < undirected.size(); b++){
            if(will_work(canReach, reachedBy, undirected[b].first, undirected[b].second, n)){
                update_canReach(canReach, reachedBy, undirected[b].first, undirected[b].second, n);
                answer.push_back(undirected[b]);
            }else if(will_work(canReach, reachedBy, undirected[b].second, undirected[b].first, n)){
                update_canReach(canReach, reachedBy, undirected[b].second, undirected[b].first, n);
                answer.push_back(make_pair(undirected[b].second, undirected[b].first));
            }else{
                works = false;
                break;
            }
        }

        if(works){
            printf("YES\n");
            for(int b = 0; b < answer.size(); b++){
                printf("%d %d\n", answer[b].first, answer[b].second);
            }
        }else{
            printf("NO\n");
        }
        /*
        for(int b = 1; b <=n; b++){
            set<int> reaches = canReach[b];
            printf("%d: ", b);
            for(auto it = reaches.begin(); it != reaches.end(); it++){
                printf("%d ", *it);
            }
            printf("\n");
        }
        */
    }
}