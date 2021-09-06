#include <bits/stdc++.h>
using namespace std;

int binarySearch(int val, int target, int l, int r){
    if(l == r){
        return l;
    }
    int mid = (l + r + 1) / 2;
    if(val/mid < target){
        return binarySearch(val, target, l, mid-1);
    }
    return binarySearch(val, target, mid, r);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long long> dp(n + 1);
    dp[1] = 1;
    long long curSum = 1;
    for (int i = 2; i <= n; i++)
    {
        long long multSum = 0;
        int j = 2;
        int last = i;
        while(i / j != last && j <= i){
            multSum += dp[i / j];
            last = i / j;
            j++;
        }
        j--;
        while (j < i)
        {
            //printf("bin search: %d %d %d\n", last, j, i);
            int next = binarySearch(i, last, j, i);
            multSum += (next - j) * dp[last];
            j = next;
            last--;
        }
        dp[i] = (multSum + curSum)%m;
        curSum += dp[i];
        curSum %= m;
        //printf("%lld\n", dp[i]);
    }
    printf("%lld\n", dp[n] % m);
}