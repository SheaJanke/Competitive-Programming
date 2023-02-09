#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> vals(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &vals[i]);
    }
    long long answer = 0;
    long long curDepth = 0;
    stack<long long> depths;
    for (int i = 0; i < n; i++){
        if(i%2 == 0){
            curDepth += vals[i];
        }else{
            answer += min(curDepth, (long long)vals[i]);
            long long last = -1;
            long long lastCount = 0;
            long long bound = curDepth - vals[i];
            if(i + 2 >= n){
                bound--;
            }
            while (!depths.empty() && depths.top() > bound)
            {
                long long depth = depths.top();
                depths.pop();
                if(depth == last){
                    lastCount++;
                }else{
                    answer += (lastCount * (lastCount + 1)) / 2;
                    lastCount = 1;
                    last = depth;
                }
            }
            answer += (lastCount * (lastCount + 1)) / 2;
            if(curDepth - vals[i] >= 0){
                depths.push(curDepth - vals[i]);
            }
            curDepth = max(curDepth - vals[i], (long long)0);
        }
    }
    printf("%lld\n", answer);
}