#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int s, r1, p1, r2, p2, c, answer;
        bool blocked = false;
        scanf("%d %d %d %d %d %d", &s, &r1, &p1, &r2, &p2, &c);
        for(int a = 0; a < c; a++){
            int c1, c2;
            scanf("%d %d", &c1, &c2);
            if(c1 == 2 and c2 == 2){
                blocked = true;
            }
        }
        if(r2 == 2 and p2 == 2){
            answer = max(c - 2, -1);
        }else if(blocked){
            answer = 0;
        }else{
            if(r1 == 2 and p1 == 2){
                answer = min(1, 2-c);
            }else{
                answer = 2-c;
            }
        }
        printf("Case #%d: %d\n",i+1, answer);
    }
}