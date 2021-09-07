#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> options = {"abc", "acb", "bac", "bca", "cab", "cba"};
    int n, m;
    scanf("%d %d", &n, &m);
    string s;
    cin >> s;
    vector<vector<int>> changes(n+1, vector<int>(options.size()));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < options.size(); j++){
            changes[i + 1][j] = changes[i][j];
            if (options[j][i % 3] != s[i])
            {
                changes[i + 1][j]++;
            }
        }
    }
    for (int i = 0; i < m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        int answer = 1e9;
        for (int j = 0; j < options.size(); j++){
            answer = min(answer, changes[r][j] - changes[l - 1][j]);
        }
        printf("%d\n", answer);
    }
}