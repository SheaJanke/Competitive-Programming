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
    vi dp(n+1, 1e9);
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        string s = to_string(i);
        if(s.size() > 1){
            for(int j = 1; j < sz(s); j++){
                string prefix = s.substr(0, j);
                string suffix = s.substr(j, sz(s) - j);
                if(suffix[0] == '0'){
                    continue;
                }
                dp[i] = min(dp[i], dp[stoi(prefix)] + dp[stoi(suffix)]);
            }
        }
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                dp[i] = min(dp[i], dp[j] + dp[i/j]);
            }
        }
    }
    cout << dp[n] << endl;
    // int maximum = 0;
    // for(int i = 1; i <= 100000; i++){
    //     maximum = max(maximum, dp[i]);
    // }
    // cout << maximum << endl;
}