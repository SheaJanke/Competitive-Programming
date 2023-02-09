#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> onlyA, onlyB, both;
    int time, Alikes, Blikes;
    for(int a = 0; a < n; a++){
        scanf("%d %d %d", &time, &Alikes, &Blikes);
        if(Alikes == 1 and Blikes == 1){
            both.push_back(time);
        }else if(Alikes == 1){
            onlyA.push_back(time);
        }else if(Blikes == 1){
            onlyB.push_back(time);
        }
    }
    if(both.size() + onlyA.size() >= k and both.size() + onlyB.size() >= k){
        sort(both.begin(), both.end());
        sort(onlyA.begin(), onlyA.end());
        sort(onlyB.begin(), onlyB.end());
        long long answer = 0;
        for(int a = 0; a < k; a++){
            if(!both.empty() and (onlyA.empty() or onlyB.empty() or both[0] <= onlyA[0] + onlyB[0])){
                answer += both[0];
                both.erase(both.begin());
            }else{
                answer += onlyA[0];
                answer += onlyB[0];
                onlyA.erase(onlyA.begin());
                onlyB.erase(onlyB.begin());
            }
        }
        printf("%lld\n", answer);
    }else{
        printf("-1\n");
    }
}