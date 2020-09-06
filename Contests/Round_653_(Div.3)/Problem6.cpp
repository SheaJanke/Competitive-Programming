#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<pair<int,int>> onlyA, onlyB, both, none;
    int time, Alikes, Blikes;
    for(int a = 0; a < n; a++){
        scanf("%d %d %d", &time, &Alikes, &Blikes);
        if(Alikes == 1 and Blikes == 1){
            both.push_back(make_pair(time,a));
        }else if(Alikes == 1){
            onlyA.push_back(make_pair(time,a));
        }else if(Blikes == 1){
            onlyB.push_back(make_pair(time,a));
        }else{
            none.push_back(make_pair(time,a));
        }
    }
    if(both.size() + onlyA.size() >= k and both.size() + onlyB.size() >= k and m >= k and max(both.size(), both.size() + (k-both.size())*2) <= m){
        vector<int> indicies;
        sort(both.begin(), both.end());
        sort(onlyA.begin(), onlyA.end());
        sort(onlyB.begin(), onlyB.end());
        sort(none.begin(), none.end());
        long long answer = 0;
        int used = 0;
        for(int a = 0; a < k; a++){
            if((!both.empty() and (onlyA.empty() or onlyB.empty() or both[0].first <= onlyA[0].first + onlyB[0].first)) or used >= m-k){
                answer += both[0].first;
                indicies.push_back(both[0].second);
                both.erase(both.begin());
            }else{
                answer += onlyA[0].first;
                indicies.push_back(onlyA[0].second);
                answer += onlyB[0].first;
                indicies.push_back(onlyB[0].second);
                onlyA.erase(onlyA.begin());
                onlyB.erase(onlyB.begin());
                used++;
            }
        }
        none.insert(none.end(), both.begin(), both.end());
        none.insert(none.end(), onlyA.begin(), onlyA.end());
        none.insert(none.end(), onlyB.begin(), onlyB.end());
        sort(none.begin(), none.end());
        for(int a = 0; a < m-k-used; a++){
            answer += none[a].first;
            indicies.push_back(none[0].second);
        }
        printf("%lld\n", answer);
        for(int a = 0; a < indicies.size(); a++){
            printf("%d ", indicies[a]+1);
        }
        printf("\n");
    }else{
        printf("-1\n");
    }
}