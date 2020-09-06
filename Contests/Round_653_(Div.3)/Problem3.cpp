#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    string brackets;
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        cin >> brackets;
        int maxDiff = 0, currDiff = 0;
        for(int b = 0; b < n; b++){
            if(brackets[b] == '('){
                currDiff--;
            }else{
                currDiff++;
                maxDiff = max(maxDiff, currDiff);
            }
        }
        printf("%d\n", maxDiff);
    }
}