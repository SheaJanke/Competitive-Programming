#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, k;
        scanf("%d %d", &n, &k);
        string s;
        cin >> s;
        bool possible = true;
        for(int a = 0; a < n; a++){
            if(a + k < n){
                if(s[a] == '?'){
                    if(s[a+k] != '?'){
                        s[a] = s[a+k];
                    }
                }else{
                    if(s[a+k] == '?'){
                        s[a+k] = s[a];
                    }else{
                        if(s[a] != s[a+k]){
                            possible = false;
                        }
                    }
                }
            }else{
                break;
            }
        }
        if(!possible){
            printf("NO\n");
            continue;
        }
        int ones = 0, zeros = 0;
        for(int a = 0; a < k; a++){
            if(s[a] == '1'){
                ones++;
            }else if(s[a] == '0'){
                zeros++;
            }
        }
        if(ones > k/2 or zeros > k/2){
            possible = false;
        }
        for(int a = 0; a < n-k; a++){
            if(s[a] == '1'){
                ones--;
            }else if(s[a] == '0'){
                zeros--;
            }
            if(s[a+k] == '1'){
                ones++;
            }else if(s[a+k] == '0'){
                zeros++;
            }
            if(ones > k/2 or zeros > k/2){
                possible = false;
            }
        }
        if(possible){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}