#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long long> dp(n + 1);
    dp[1] = 1;
    long long curSum = 1;
    long long curMult = 0;
    vector<long long> multDp(n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        curMult += multDp[i];
        dp[i] = (curSum + curMult)%m;
        for (int j = 2 * i; j <= n; j+=i){
            multDp[j] += (dp[i] - dp[i - 1]);
        }
        curSum += dp[i];
    }
    printf("%lld\n", dp[n] % m);
}