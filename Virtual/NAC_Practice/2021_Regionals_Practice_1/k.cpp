#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;
    int d;
    for(int i = 0; i < n-1; i++){
        cin >> d;
    }
    vector<ll> dp(k+2);
    dp[1] = k;
    for(int i = 1; i < n; i++){
        vector<ll> nextDp(k+2);
        for(int j = 1; j <= k; j++){
            ll left = j-1;
            ll right = k - j;
            nextDp[j] += dp[j] * left;
            nextDp[j+1] += dp[j] * right;
            nextDp[j] %= mod;
        }
        dp = nextDp;
    }
    cout << dp[k] << endl;

}