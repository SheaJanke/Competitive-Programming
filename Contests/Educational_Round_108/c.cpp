#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
        int n;
        scanf("%d", &n);
        vector<long long> unis(n), vals(n);
        long long val;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &val);
            unis[i] = val - 1;
        }
        for (int i = 0; i < n; i++){
            scanf("%lld", &vals[i]);
        }
        vector<vector<long long>> teams(n);
        for (int i = 0; i < n; i++){
            teams[unis[i]].push_back(vals[i]);
        }
        for (int i = 0; i < n; i++){
            long long cur = 0;
            sort(teams[i].begin(), teams[i].end());
            reverse(teams[i].begin(), teams[i].end());
            for (int j = 0; j < teams[i].size(); j++)
            {
                cur += teams[i][j];
                teams[i][j] = cur;
            }
        }
        vector<long long> answers(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < teams[i].size(); j++){
                int sz = teams[i].size();
                int rem = sz % (j + 1);
                int addIndex = sz - 1 - rem;
                if(addIndex >= 0){
                    answers[j] += teams[i][addIndex];
                }
            }
        }
        for (int i = 0; i < n; i++){
            printf("%lld ", answers[i]);
        }
        printf("\n");
    }
}