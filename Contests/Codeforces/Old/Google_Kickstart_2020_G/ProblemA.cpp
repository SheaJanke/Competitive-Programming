#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        string s;
        cin >> s;
        long long answer = 0, start = 0;
        for(int j = s.size()-1; j >= 0; j--){
            if(s.substr(j, 5) == "START"){
                start++;
            }else if(s.substr(j,4) == "KICK"){
                answer += start;
            }
        }
        printf("Case #%d: %lld\n", i+1, answer);
    }
}