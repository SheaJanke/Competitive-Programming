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
    vi vals(4);
    int start, finish;
    char d;
    int target;
    for (int i = 0; i < 4; i++)
    {
        cin >> start >> d >> finish;
        vals[i] = start * 100 + finish;
        //cout << vals[i] << endl;
    }
    cin >> start >> d >> finish;
    target = start * 100 + finish;
    sort(all(vals));
    if (vals[0] + vals[1] + vals[2] > target * 3)
    {
        cout << "impossible" << endl;
        exit(0);
    }
    if (vals[1] + vals[2] + vals[3] <= target * 3)
    {
        cout << "infinite" << endl;
        exit(0);
    }
    int answer = target * 3 - vals[1] - vals[2];
    string s = to_string(answer);
    for(int i = 0; i < sz(s) - 2; i++){
        cout << s[i];
    }
    cout << '.' << s[sz(s) - 2] << s[sz(s) - 1] << endl;
    //cout << answer / 100 << '.' << answer % 100 << endl;
}