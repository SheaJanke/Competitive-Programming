#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vi dependency;
vi numPages;
vector<bool> isCulminating;

vector<bool> used;

void dfs(int cur) {
    if(cur == -1 || used[cur]){
        return;
    }
    used[cur] = true;
    dfs(dependency[cur]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin >> n >> m;
    dependency = vi(n, -1);
    numPages = vi(n);
    isCulminating = vector<bool>(n, true);
    for(int i  = 0; i < n; i++){
        cin >> numPages[i];
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        dependency[b] = a;
        isCulminating[a] = false;
    }
    int answer = 1e9;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(isCulminating[i] && isCulminating[j]){
                used = vector<bool>(n);
                dfs(i);
                dfs(j);
                int curAnswer = 0;
                for(int k = 0; k < n; k++){
                    if(used[k]){
                        curAnswer += numPages[k];
                    }
                }
                answer = min(answer, curAnswer);
            }
        }
    }
    cout << answer << endl;
}