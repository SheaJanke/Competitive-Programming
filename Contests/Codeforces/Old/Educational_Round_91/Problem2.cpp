#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        string robotString;
        cin >> robotString;
        int r = 0, p = 0, s = 0;
        for(int a = 0; a < robotString.length(); a++){
            if(robotString[a] == 'R'){
                r++;
            }else if(robotString[a] == 'P'){
                p++;
            }else{
                s++;
            }
        }
        char answer;
        if(r >= p and r >= s){
            answer = 'P';
        }else if(p >= r and p >= s){
            answer = 'S';
        }else{
            answer = 'R';
        }
        for(int a = 0; a < robotString.length(); a++){
            printf("%c", answer);
        }
        printf("\n");
    }
}