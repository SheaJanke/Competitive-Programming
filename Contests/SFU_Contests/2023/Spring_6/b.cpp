#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s, cur;
    try
    {
        while (true)
        {
            cin >> cur;
            for (int i = 0; i < cur.size(); i++)
            {
                if (isalpha(cur[i]))
                {
                    s.push_back(tolower(cur[i]));
                }
            }
        }
    }
    catch (...)
    {
    }
    int n = sz(s);
    vector<vi> dp(n + 1, vi(n + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i] == s[n - j - 1])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << n - dp[n][n] << endl;
}