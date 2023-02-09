#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; j++){
        long long answer = 0;
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        answer = (n-1) + (n * (m-1));
        if(answer != k){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
}