#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> vals(n);
    for(int i = 0; i < n; i++){
        cin >> vals[i];
    }
    if(k == 1){
        for(int i = 0; i < n; i++){
            printf("%.12lf ", ((double)100)/n);
        }
        cout << endl;
        exit(0);
    }
    for(int i = 0; i < n; i++){
        double curNum = vals[i];
        double totalNum = vals[i];
        double totalDenom = 1;
        double curRatio = 1;
        for(int j = 0; j < (n-k); j++){
            int num = n - 2 - j;
            int denom = num - (k-2);
            curRatio = curRatio * denom / num;
            curNum += vals[(i - j - 1 + n) % n];
            totalNum += curRatio * curNum;
            totalDenom += curRatio;
        }
        printf("%.12lf ", totalNum / totalDenom * k / n);
    }
    cout << endl;
}