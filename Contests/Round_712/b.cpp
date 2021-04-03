#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d\n", &t);
    for (int k = 0; k < t; k++){
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        if(n == 1){
            if(s1[0] == s2[0]){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
            continue;
        }
        bool works = true;
        bool same = true;
        if(s1[0] != s2[0]){
            same = false;
        }
        int zeros = 0, ones = 0;
        if(s1[0] == '0'){
            zeros++;
        }else{
            ones++;
        }
        for (int i = 1; i < n; i++){
            if(s1[i] == s2[i]){
                if(same == false){
                    if(zeros != ones){
                        works = false;
                    }
                }
                same = true;
            }else{
                if(same == true){
                    if(zeros != ones){
                        works = false;
                    }
                }
                same = false;
            }
            if(s1[i] == '0'){
                zeros++;
            }else{
                ones++;
            }
        }
        if(!same && zeros != ones){
            works = false;
        }
        if(works){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}