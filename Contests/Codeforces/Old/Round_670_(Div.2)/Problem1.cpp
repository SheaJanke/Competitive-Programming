#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        map<int,int> counts;
        for(int a = 0; a <= 110; a++){
            counts[a] = 0;
        }
        int num;
        for(int a = 0; a < n; a++){
            scanf("%d", &num);
            counts[num]++;
        }
        int answer = 0;
        for(int a = 0; a <= 110; a++){
            if(counts[a] < 2){
                answer += a;
                break;
            }
        }
        for(int a = 0; a <= 110; a++){
            if(counts[a] < 1){
                answer += a;
                break;
            }
        }
        printf("%d\n", answer);



    }
}