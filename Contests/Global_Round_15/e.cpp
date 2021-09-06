#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tSet;
// Supports .order_of_key(x), counts number of elements less than x.
// Supports .find_by_order(n), returns iterator to nth element (0-indexed)

long long power(long long x, unsigned int y, long long p)
{
    long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main(){
    long long p = 998244353;
    int n;
    cin >> n;
    vector<vector<long long>> vals(n);
    for (int i = 0; i < n; i++){
        long long x, y, s;
        cin >> x >> y >> s;
        vals[i] = {x, y, s};
    }
    long long answer = vals[n - 1][0] + 1;
    tSet portals;
    for (int i = n-1; i >= 0; i--){
        int count = portals.order_of_key(vals[i][0]);
        portals.insert(vals[i][1]);
        answer += (vals[i][0] - vals[i][1]) * (power(2, count, p)-1 + vals[i][2]);
        answer = answer % p;
    }
    printf("%lld\n", answer);
}