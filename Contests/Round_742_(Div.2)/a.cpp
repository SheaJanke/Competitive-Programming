#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        string answer = "";
        for (int i = 0; i < n; i++){
            if(s[i] == 'U'){
                answer += 'D';
            }else if(s[i] == 'D'){
                answer += 'U';
            }else{
                answer += s[i];
            }
        }
        cout << answer << endl;
    }
}