#include <bits/stdc++.h>
using namespace std;

bool hasIntersection(pair<int, int> &c1, pair<int,int> &c2){
    vector<pair<int, int>> vals;
    vals.push_back({c1.first, 1});
    vals.push_back({c1.second, 1});
    vals.push_back({c2.first, 2});
    vals.push_back({c2.second, 2});
    sort(vals.begin(), vals.end());
    return vals[0].second == vals[2].second;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int z = 0; z < t; z++){
        int n, k;
        cin >> n >> k;
        set<int> rem;
        for (int i = 1; i <= 2 * n; i++){
            rem.emplace(i);
        }
        vector<pair<int, int>> pairs;
        for (int i = 0; i < k; i++)
        {
            int val1, val2;
            cin >> val1 >> val2;
            pairs.push_back(make_pair(val1, val2));
            rem.erase(val1);
            rem.erase(val2);
        }
        vector<int> left(rem.begin(), rem.end());
        for (int i = 0; i < n - k; i++){
            pairs.push_back(make_pair(left[i], left[i + (n - k)]));
        }
        long long answer = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if(hasIntersection(pairs[i], pairs[j])){
                    answer++;
                }
            }
        }
        printf("%lld\n", answer);
    }
}