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
    bool works = true;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s != "mumble"){
            int cur = stoi(s);
            if(cur != i + 1){
                works = false;
            }
        }
    }
    if(works) {
        cout << "makes sense" << endl;
    }else {
        cout << "something is fishy" << endl;
    }
}