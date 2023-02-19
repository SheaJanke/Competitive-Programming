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
    vector<pii> vals;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        vals.push_back({val, i});
    }
    set<int> s;
    s.emplace(-1);
    s.emplace(n);
    sort(all(vals));
    ll best = 0;
    int bestStart = 1, bestEnd = n;
    for(int i = 0; i < n; i++){
        int val = vals[i].first;
        int index = vals[i].second;
        auto it = s.lower_bound(index);
        int end = *it;
        it--;
        int start = *it;
        ll cur = (ll)(end - start - 1) * (ll)val;
        if(cur > best){
            best = cur;
            bestStart = start+2;
            bestEnd = end;
        }else if(cur == best){
            if(start+2 < bestStart){
                bestStart = start+2;
                bestEnd = end;
            }
        }
        s.emplace(index);
    }
    cout << bestStart << " " << bestEnd << " " << best << endl;
}