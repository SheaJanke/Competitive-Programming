#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        bool found =false;
        set<int> vals;
        for(int j = 0; j < n; j++){
            int val;
            scanf("%d", &val);
            if(vals.count(val) != 0){
                found = true;
            }
            vals.emplace(val);
        }
        if(found){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}