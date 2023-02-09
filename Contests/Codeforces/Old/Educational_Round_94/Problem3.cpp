#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        string str;
        cin >> str;
        int x;
        scanf("%d", &x);
        int answer[str.size()];
        for(int b = 0; b < str.size(); b++){
            answer[b] == -1;
        }
        bool possible = true;
        for(int b = 0; b < str.size(); b++){
            if(str[b] == '0'){
                if(b-x > 0){

                }else if(b+x < str.size()){

                }else{
                    
                }
            }
        }
    }
}