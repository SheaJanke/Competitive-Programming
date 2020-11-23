#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, m;
        scanf("%d %d", &n, &m);
        bool found = false;
        for(int b = 0; b < n; b++){
            int i,j,k,l;
            scanf("%d %d %d %d", &i, &j, &k, &l);
            if(j == k){
                found = true;
            }
        }
        if(found and m%2 == 0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}