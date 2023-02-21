#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int offset = 1e9;
unordered_map<int, vi> edges;
vector<vi> proof;
unordered_set<int> visited;

void dfs(int cur, int parent)
{
    visited.emplace(cur);
    for (int i = 0; i < edges[cur].size(); i++)
    {
        int next = edges[cur][i];
        if (visited.count(next) == 0)
        {
            if(cur <= offset) {
                proof.push_back({parent - offset, next - offset, cur});
            }
            dfs(next, cur);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            edges[val].push_back(i + offset);
            edges[i + offset].push_back(val);
        }
    }
    dfs(1 + offset, -1);
    if (sz(proof) < n - 1)
    {
        cout << "impossible" << endl;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << proof[i][j] << " ";
            }
            cout << endl;
        }
    }
}