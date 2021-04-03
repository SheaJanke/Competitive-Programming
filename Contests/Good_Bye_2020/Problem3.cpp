#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++){
        string s;
        cin >> s;
        int n = s.size();
        vector<bool> changed(n);
        int changedCount = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if(s[i] == s[i+1] && !changed[i] && !changed[i+1]){
                changed[i + 1] = true;
                changedCount++;
            }
            if(i < n-2 && s[i] == s[i+2] && !changed[i] && !changed[i+2]){
                changed[i + 2] = true;
                changedCount++;
            }
        }
        printf("%d\n", changedCount);
    }
}