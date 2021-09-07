#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<long long> vals(n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &vals[i]);
    }
    long long answer = 0;
    long long curDepth = 0;
    priority_queue<long long> endDepths;
    for (int i = 0; i < n; i++)
    {
        if(i%2 == 0){
            curDepth += vals[i];
        }else{
            long long newDepth = curDepth - vals[i];
            answer += min(curDepth, vals[i]);
            if(i == n-1 || i == n-2){
                newDepth--;
            }
            while(!endDepths.empty() && endDepths.top() > newDepth){
                long long val = endDepths.top();
                endDepths.pop();
                long long valCount = 1;
                while(!endDepths.empty() && endDepths.top() == val){
                    valCount++;
                    endDepths.pop();
                }
                answer += (valCount * (valCount + 1)) / 2;
            }
            if(newDepth >= 0){
                endDepths.push(newDepth);
            }
            curDepth = max(newDepth, 0ll);
        }
    }
    printf("%lld\n", answer);
}