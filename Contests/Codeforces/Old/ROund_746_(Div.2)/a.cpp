#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int n, h;
        scanf("%d %d", &n, &h);
        vector<int> vals(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vals[i]);
        }
        sort(vals.begin(), vals.end());
        int sum = vals[n - 1] + vals[n - 2];
        int turns = h / sum;
        turns *= 2;
        int rem = h % sum;
        if(rem > 0){
            rem -= vals[n - 1];
            turns++;
        }
        if(rem > 0){
            turns++;
        }
        printf("%d\n", turns);
    }
}