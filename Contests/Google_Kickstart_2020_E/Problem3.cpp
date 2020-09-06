#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        vector<pair<long long, long long>> e_r;
        long long totalE = 0;
        for(int b = 0; b < n; b++){
            long long e,r;
            scanf("%lld %lld", &e, &r);
            totalE += e;
            e_r.push_back(make_pair(e,r));
        }
        long long curRemoved = 0, maxRemoved = 0, curScore = totalE, maxScore = totalE, subtract = 0;
        multiset<pair<long long, long long>> rem_value;
        for(int b = 0; b < n; b++){
            int rem = totalE - e_r[b].first - e_r[b].second;
            if(rem-subtract >= 0){
                curScore += e_r[b].first;
                rem_value.emplace(make_pair(rem, e_r[b].first));
            }else{
                curRemoved++;
                curScore -= e_r[b].first;
                subtract += e_r[b].first;
                while(!rem_value.empty() and rem_value.begin()->first - subtract < 0){
                    subtract += rem_value.begin()->second;
                    curScore -= 2 * rem_value.begin()->second;
                    curRemoved++;
                    rem_value.erase(rem_value.begin());
                }
            }
            if(curScore > maxScore){
                maxScore = curScore;
                maxRemoved = curRemoved;
            }
        }
        if(!rem_value.empty()){
            printf("Case #%d: %lld INDEFINITELY\n", a+1, curRemoved);
        }else{
            printf("Case #%d: %lld %lld\n", a+1, maxRemoved, maxScore);
        }
    }
}