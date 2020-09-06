#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        set<int> seen;
        int newNum;
        for(int b = 0; b < 2*n; b++){
            scanf("%d", &newNum);
            if(find(seen.begin(), seen.end(), newNum) != seen.end()){
                printf("%d ", newNum);
            }else{
                seen.insert(newNum);
            }
        }
        printf("\n");
    }
}