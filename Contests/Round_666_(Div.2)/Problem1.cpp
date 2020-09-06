#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int counts[26];
        for(int b = 0; b < 26; b++){
            counts[b] = 0;
        }
        int n;
        scanf("%d", &n);
        string str;
        for(int b = 0; b < n; b++){
            cin >> str;
            for(int c = 0; c < str.size(); c++){
                counts[(int)str[c] - 97]++;
            }
        }
        bool possible = true;
        for(int b = 0; b < 26; b++){
            if(counts[b]%n != 0){
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