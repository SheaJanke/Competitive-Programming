#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<long long, long long>> vals;
    long long startA, startC;
    scanf("%lld %lld", &startA, &startC);
    long long minCost = 0;
    for (int i = 1; i < n; i++)
    {
        long long a, c;
        scanf("%lld %lld", &a, &c);
        vals.push_back({a, c});
        minCost += c;
    }
    sort(vals.begin(), vals.end());
    long long extraCost = 0;
    long long reach = vals[n-2].first - vals[n-2].second;
    for (int i = n - 2; i >= 0; i--)
    {
        if(vals[i].first - vals[i].second < reach){
            extraCost += max(reach - vals[i].first, (long long)0);
            reach = vals[i].first - vals[i].second;
        }
    }
    printf("%lld\n", minCost + extraCost + startC);
}