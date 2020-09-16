#include <bits/stdc++.h>
using namespace std;

void getDistances(int curVert, int fromVert, map<int, set<int>> &vertices, map<int, map<int,int>> &distances){
    for(auto it = vertices[curVert].begin(); it != vertices[curVert].end(); it++){
        if(*it != fromVert){
            getDistances(*it, curVert, vertices, distances);
            int distance = 0;
            for(auto it2 = distances[*it].begin(); it2 != distances[*it].end(); it2++){
                distance += (*it2).second;
            }
            distances[curVert][*it] = distance + 1;
        }
    }
}

void updateDistances(int curVert, int fromVert, map<int, set<int>> &vertices, map<int, map<int,int>> &distances){
    int distance = 0;
    if(fromVert != -1){
        for(auto it = distances[fromVert].begin(); it != distances[fromVert].end(); it++){
            if(it->first != curVert){
                distance += it->second;
            }
        }
        distances[curVert][fromVert] =  distance + 1;
    }
    for(auto it = vertices[curVert].begin(); it != vertices[curVert].end(); it++){
        if(*it != fromVert){
            updateDistances(*it, curVert, vertices, distances);
        }
    }
}


int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        map<int, set<int>> verticies;
        for(int a = 1; a <= n; a++){
            set<int> newSet;
            verticies[a] = newSet;
        }
        for(int a = 0; a < n-1; a++){
            int x, y;
            scanf("%d %d", &x, &y);
            verticies[x].emplace(y);
            verticies[y].emplace(x);
        }
        map<int,map<int,int>> distances;
        for(int a = 1; a <= n; a++){
            map<int, int> newMap;
            for(auto it = verticies[a].begin(); it != verticies[a].end(); it++){
                newMap[*it] = 0;
            }
            distances[a] = newMap;
        }
        getDistances(1, -1, verticies, distances);
        updateDistances(1,-1, verticies, distances);
        set<int> centroids;
        int minDistance = 1000000;
        for(int a = 1; a <= n; a++){
            int curMaxDistance = 0;
            for(auto it = distances[a].begin(); it != distances[a].end(); it++){
                curMaxDistance = max(curMaxDistance, it->second);
            }
            if(curMaxDistance < minDistance){
                centroids = set<int>();
                centroids.insert(a);
                minDistance = curMaxDistance;
            }else if(curMaxDistance == minDistance){
                centroids.insert(a);
            }
        }
        if(centroids.size() == 1){
            printf("1 %d\n", *verticies[1].begin());
            printf("1 %d\n", *verticies[1].begin());
        }else{
            int x, y, firstCentroid = *centroids.begin();
            for(auto it = verticies[firstCentroid].begin(); it != verticies[firstCentroid].end(); it++){
                if(centroids.find(*it) == centroids.end()){
                    x = firstCentroid;
                    y = *it;
                }
            }
            printf("%d %d\n", x, y);
            centroids.erase(centroids.begin());
            printf("%d %d\n", *centroids.begin(), y);
        }
        /*
        printf("Verticies:\n");
        for(int a = 1; a <= n; a++){
            printf("%d : ", a);
            for(auto it = verticies[a].begin(); it != verticies[a].end(); it++){
                printf("%d ", *it);
            }
            printf("\n");
        }
        printf("Distances:\n");
        for(int a = 1; a <= n; a++){
            printf("%d :\n\t", a);
            for(auto it = distances[a].begin(); it != distances[a].end(); it++){
                printf("%d : %d, ", it->first, it->second);
            }
            printf("\n");
        }
        */
    }
}