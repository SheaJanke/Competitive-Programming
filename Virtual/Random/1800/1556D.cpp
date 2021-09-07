#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> vals(n);
    long long or12, or13, or23, and12, and13, and23;
    cout << "or 1 2" << endl;
    cin >> or12;
    cout << "or 1 3" << endl;
    cin >> or13;
    cout << "or 2 3" << endl;
    cin >> or23;
    cout << "and 1 2" << endl;
    cin >> and12;
    cout << "and 1 3" << endl;
    cin >> and13;
    cout << "and 2 3" << endl;
    cin >> and23;
    long long sum123 = (or12 + or13 + or23 + and12 + and13 + and23) / 2;
    vals[2] = sum123 - (or12 + and12);
    vals[1] = sum123 - (or13 + and13);
    vals[0] = sum123 - (or23 + and23);
    for (int i = 3; i < n; i++)
    {
        int orCur, andCur;
        cout << "or 1 " << i + 1 << endl;
        cin >> orCur;
        cout << "and 1 " << i + 1 << endl;
        cin >> andCur;
        vals[i] = (orCur + andCur) - vals[0];
    }
    sort(vals.begin(), vals.end());
    cout << "finish " << vals[k - 1] << endl;
}