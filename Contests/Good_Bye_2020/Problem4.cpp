#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++){
        int n;
        scanf("%d", &n);
        long long weights[n];
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &weights[i]);
            total += weights[i];
        }
        vector<bool> seen(n);
        multiset<long long> extras;
        for (int i = 0; i < n - 1; i++)
        {
            int first, second;
            scanf("%d %d", &first, &second);
            if(seen[first-1]){
                extras.emplace(-weights[first - 1]);
            }
            seen[first - 1] = true;
            if(seen[second-1]){
                extras.emplace(-weights[second - 1]);
            }
            seen[second - 1] = true;
        }
        printf("%lld ", total);
        while(!extras.empty()){
            total -= *extras.begin();
            printf("%lld ", total);
            extras.erase(extras.begin());
        }
        printf("\n");
    }
}