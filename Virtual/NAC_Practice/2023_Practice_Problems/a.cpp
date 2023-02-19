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

    string s1, s2;
    cin >> s1 >> s2;
    int answer = 1;
    for(int i = 0; i < 4; i++){
        if(s1[i] != s2[i]) {
            answer *= 2;
        }
    }
    cout << answer << endl;
}