#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        string s, s2;
        cin >> s;
        s2 = s;
        sort(s.begin(), s.end());
        long long answer = 0;
        for (int i = 0; i < n; i++){
            if(s2[i] != s[i]){
                answer++;
            }
        }
        printf("%lld\n", answer);
    }
}