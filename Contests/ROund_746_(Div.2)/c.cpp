#include <bits/stdc++.h>
using namespace std;

vector<int> vals;
map<int, vector<int>> edges;
vector<bool> visited;
int numSubtrees = 0;
int target = 0;

int dfs(int curNode){
    if(visited[curNode]){
        return 0;
    }
    visited[curNode] = true;
    int curXOR = 0;
    for (int i = 0; i < edges[curNode].size(); i++){
        curXOR ^= dfs(edges[curNode][i]);
    }
    curXOR ^= vals[curNode];
    if(curXOR == target) {
        numSubtrees++;
        return 0;
    }
    return curXOR;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int n, k;
        scanf("%d %d", &n, &k);
        vals = vector<int>(n + 1);
        edges = map<int, vector<int>>();
        visited = vector<bool>(n + 1);
        target = 0;
        numSubtrees = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &vals[i]);
            target = target ^ vals[i];
        }
        for (int i = 0; i < n - 1; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        if(target == 0){
            printf("YES\n");
        }else{
            dfs(1);
            //printf("%d\n", numSubtrees);
            if (k == 2 || numSubtrees < 3)
            {
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }
}