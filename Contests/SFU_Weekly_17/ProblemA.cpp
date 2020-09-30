#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int m, l, r, k;
    scanf("%d", &m);
    for(int a = 0; a < m; a++){
        scanf("%d %d %d", &l, &r, &k);
        int length = (r - l + 1);
        int shift  = k%length;
        string newSubstring = "";
        for(int b = 0; b < length; b++){
            newSubstring += s[(l-1) + (length - shift + b)%length];
        }
        s.replace(s.begin() + l - 1, s.begin() + r, newSubstring.begin(), newSubstring.end());
    }
    cout << s << endl;
}