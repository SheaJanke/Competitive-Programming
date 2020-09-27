#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int answer = 0, n, k, start, end;
        scanf("%d %d", &n ,&k);
        vector<pair<int,int>> intervals;
        for(int j = 0; j < n; j++){
            scanf("%d %d", &start, &end);
            intervals.push_back(make_pair(start, end-start));
        }
        sort(intervals.begin(), intervals.end());
        int curTime = 0;
        for(int a = 0; a < intervals.size(); a++){
            int beg = intervals[a].first, stop = intervals[a].second;
            if(curTime < beg + stop){
                int addition = ((beg + stop) - max(beg, curTime) - 1)/k + 1;
                answer += addition;
                curTime = max(curTime, beg) + k * addition;
            }
        }
        printf("Case #%d: %d\n",i+1, answer);
    }
}