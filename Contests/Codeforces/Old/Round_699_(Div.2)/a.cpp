#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
        int x, y;
        scanf("%d %d", &x, &y);
        string s;
        cin >> s;
        int u = 0, d = 0, l = 0, r = 0;
        for (int i = 0; i < s.size(); i++){
            if(s[i] == 'U'){
                u++;
            }else if(s[i] == 'D'){
                d++;
            }else if(s[i] == 'R'){
                r++;
            }else{
                l++;
            }
        }
        bool works = true;
        if (x < 0){
            if(l < abs(x)){
                works = false;
            }
        }else{
            if(r < x){
                works = false;
            }
        }
        if(y < 0){
            if(d < abs(y)){
                works = false;
            }
        }else{
            if(u < abs(y)){
                works = false;
            }
        }
        if(works){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}