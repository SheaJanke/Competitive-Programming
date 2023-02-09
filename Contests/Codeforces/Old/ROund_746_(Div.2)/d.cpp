#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> edges;
vector<bool> visited;
set<int> remaining;
set<int> newRemaining;

void dfs(int curNode){
    if(newRemaining.size() > remaining.size()/2){
        return;
    }
    if(remaining.find(curNode) == remaining.end()){
        return;
    }
    if(visited[curNode]){
        return;
    }
    visited[curNode] = true;
    newRemaining.emplace(curNode);
    for (int i = 0; i < edges[curNode].size(); i++){
        dfs(edges[curNode][i]);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    visited = vector<bool>(n+1);
    for (int i = 1; i <= n; i++){
        remaining.emplace(i);
    }
    int targetVal = 0;
    cout << "? " << n << " ";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    cin >> targetVal;
    while (remaining.size() > 2)
    {
        visited = vector<bool>(n + 1);
        newRemaining = set<int>();
        dfs(*remaining.begin());
        cout << "? " << newRemaining.size() << " ";
        for (auto it = newRemaining.begin(); it != newRemaining.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        int dist;
        cin >> dist;
        //cout << "dist " << dist << "target val: " << targetVal << endl;
        set<int> actualRemaining;
        for (auto it = remaining.begin(); it != remaining.end(); it++){
            bool fullyContained = true;
            if(newRemaining.find(*it) == newRemaining.end()){
                fullyContained = false;
            }
            for (int i = 0; i < edges[*it].size(); i++){
                int edgeVal = edges[*it][i];
                if(remaining.find(edgeVal) == remaining.end()){
                    if(newRemaining.find(edgeVal) == newRemaining.end()){
                        fullyContained = false;
                    }
                }
            } 
            //cout << "*it " << *it  << fullyContained << endl;
            if(dist == targetVal){
                if(newRemaining.find(*it) != newRemaining.end()){
                    actualRemaining.emplace(*it);
                }
            }else{
                if(!fullyContained){
                    actualRemaining.emplace(*it);
                }
            }
        }
        remaining = actualRemaining;
    }
    int val1 = *remaining.begin();
    int val2 = *(++remaining.begin());
    cout << "! " << val1 << " " << val2 << endl;
}