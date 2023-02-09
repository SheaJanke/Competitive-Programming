#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        int n, m;
        scanf("%d", &n);
        int curSumN = 0, maxSumN = 0, val;
        for (int j = 0; j < n; j++){
            scanf("%d", &val);
            curSumN += val;
            maxSumN = max(maxSumN, curSumN);
        }
        scanf("%d", &m);
        int curSumM = 0, maxSumM = 0;
        for (int j = 0; j < m; j++){
            scanf("%d", &val);
            curSumM += val;
            maxSumM = max(maxSumM, curSumM);
        }
        printf("%d\n", maxSumN + maxSumM);
    }
}