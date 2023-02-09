#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int n, x;
        scanf("%d %d", &n, &x);
        vector<int> vals(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vals[i]);
        }
        vector<int> sortedVals(vals.begin(), vals.end());
        sort(sortedVals.begin(), sortedVals.end());
        bool works = true;
        for (int i = 0; i < n; i++)
        {
            if(i - x < 0 && i + x >= n){
                if(vals[i] != sortedVals[i]){
                    works = false;
                }
            }
        }
        if(works){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}