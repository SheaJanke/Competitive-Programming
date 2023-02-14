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
    vector<bool> has(366);
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        has[val] = true;
    }
    int curTotal = 0;
    int curDirty = 0;
    int answer = 0;
    for(int i = 0; i <= 365; i++){
        if(has[i]){
            curDirty += 1;
        }
        if(curTotal + curDirty >= 20){
            //cout << i << endl;
            answer++;
            curTotal = 0;
            curDirty = 0;
        }
        curTotal += curDirty;
    }
    if(curTotal > 0){
        //cout << 365 << endl;
        answer++;
    }
    cout << answer << endl;
}