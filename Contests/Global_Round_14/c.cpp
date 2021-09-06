#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int z = 0; z < t; z++){
        int n, m, x;
        scanf("%d %d %d", &n, &m, &x);
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++){
            int val;
            scanf("%d", &val);
            arr.push_back({val, i});
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        set<pair<int, int>> q;
        for (int i = 0; i < m; i++){
            q.emplace(make_pair(0, i + 1));
        }
        vector<int> answer(n);
        vector<int> towers(m);
        for (int i = 0; i < n; i++)
        {
            auto it = q.begin();
            towers[it->second - 1] += arr[i].first;
            answer[arr[i].second] = it->second;
            int index = it->second;
            int val = towers[index - 1];
            q.erase(it);
            q.emplace(make_pair(val, index));
        }
        int minimum = *min_element(towers.begin(), towers.end());
        int maximum = *max_element(towers.begin(), towers.end());
        if(maximum - minimum <= x){
            printf("YES\n");
            for (int i = 0; i < n; i++){
                printf("%d ", answer[i]);
            }
            printf("\n");
        }else{
            printf("NO\n");
        }
    }
}