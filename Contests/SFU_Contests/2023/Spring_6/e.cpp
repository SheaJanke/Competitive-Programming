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
    n--;
    vector<ll> vals(n);
    for(int i = 0; i < n; i++){
        cin >> vals[i];
    }
    vector<ll> endLeft(n+1), endRight(n+1);
    ll answer = 0;
    for(int i = n-1; i >= 0; i--){
        if(vals[i] % 2 == 0){
            endLeft[i] = endLeft[i+1] + vals[i];
            endRight[i] = max(endLeft[i+1], endRight[i+1]) + vals[i] - 1;
            answer = max(answer, endRight[i+1] + vals[i]);
        }else{
            if(vals[i] > 1){
                endLeft[i] = endLeft[i+1] + vals[i] - 1;
            }
            endRight[i] = max(endLeft[i+1], endRight[i+1]) + vals[i];
        }
        //cout << endLeft[i] << " " << endRight[i] << endl;
        answer = max(answer, endLeft[i]);
        answer = max(answer, endRight[i]);
    }
    reverse(all(vals));
    endLeft = vector<ll>(n+1), endRight = vector<ll>(n+1);
    for(int i = n-1; i >= 0; i--){
        if(vals[i] % 2 == 0){
            endLeft[i] = endLeft[i+1] + vals[i];
            endRight[i] = max(endLeft[i+1], endRight[i+1]) + vals[i] - 1;
            answer = max(answer, endRight[i+1] + vals[i]);
        }else{
            if(vals[i] > 1){
                endLeft[i] = endLeft[i+1] + vals[i] - 1;
            }
            endRight[i] = max(endLeft[i+1], endRight[i+1]) + vals[i];
        }
        //cout << endLeft[i] << " " << endRight[i] << endl;
        answer = max(answer, endLeft[i]);
        answer = max(answer, endRight[i]);
    }
    cout << answer << endl;
}