#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, q;
        string s;
        scanf("%d %d", &n, &q);
        cin >> s;
        for(int j = 0; j < q; j++){
            int l, r;
            scanf("%d %d", &l, &r);
            bool found = false;
            for(int k = l-2; k >= 0; k--){
                if(s[k] == s[l-1]){
                    found = true;
                }
            }
            for(int k = r; k < n; k++){
                if(s[k] == s[r-1]){
                    found = true;
                }
            }
            if(found){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
}