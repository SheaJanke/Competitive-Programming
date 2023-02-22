#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<pii> intervals(n);
    for(int i =  0; i < n ;i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    intervals.push_back({2e9, 2e9});
    vector<int> counts(n+1);
    unordered_set<int> pegs;
    int p;
    cin >> p;
    for(int i = 0 ; i < p; i++){
        int val;
        cin >> val;
        pegs.emplace(val);
        for(int j = 0; j < n; j++){
            if(val >= intervals[j].first && val <= intervals[j].second){
                counts[j]++;
            }
        }
    }
    bool works = true;
    for(int i = 0 ; i <= n; i++){
        if(counts[i] > 2){
            works = false;
        }
    }
    if(!works){
        cout << "impossible" << endl;
        exit(0);
    }
    vi answer;
    for(int i = 0; i < n; i++){
        if(counts[i] == 2){
            continue;
        }
        if(counts[i+1] < 2 && intervals[i].second == intervals[i+1].first && pegs.count(intervals[i].second) == 0){
            answer.push_back(intervals[i].second);
            counts[i]++;
            counts[i+1]++;
        }
        int j = intervals[i].second - 1;
        while(counts[i] < 2){
            if(pegs.count(j) == 0){
                answer.push_back(j);
                counts[i]++;
            }
            j--;
        }
    }
    cout << answer.size() << endl;
    for(int i = 0 ; i < sz(answer); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}