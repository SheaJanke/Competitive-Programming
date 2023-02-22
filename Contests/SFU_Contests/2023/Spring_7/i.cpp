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
    vi vals(n);
    for(int i = 0; i < n; i++){
        cin >> vals[i];
    }
    int startDown = -1;
    for(int i = 0; i < n-1; i++){
        if(vals[i+1] < vals[i]){
            startDown = i;
            break;
        }
    }
    if(startDown == -1){
        cout << "1 1" << endl;
        exit(0);
    }
    int r = -1;
    for(int i = startDown; i < n-1; i++){
        if(vals[i+1] > vals[i]){
            break;
        }
        r = i+1;
    }
    int l = r;
    while(l > 0 && vals[l-1] >= vals[l]){
        l--;
    }
    int answerStart = l+1;
    int answerEnd = r+1;
    while(l < r){
        swap(vals[l], vals[r]);
        l++;
        r--;
    }
    bool works = true;
    for(int i = 0; i < n-1; i++){
        if(vals[i+1] < vals[i]){
            works = false;
        }
    }
    if(works){
        cout << answerStart << " " << answerEnd << endl;
    }else{
        cout << "impossible" << endl;
    }
    
}