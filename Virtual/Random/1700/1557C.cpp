#include <bits/stdc++.h>
using namespace std;

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
    long long p = 1000000007;
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int n, k;
        long long answer = 0;
        scanf("%d %d", &n, &k);
        for (int i = 0; i <= k; i++){
            long long additionL = 1, additionR = 1;
            if (n % 2 == 0)
            {
                additionL = power(2, n-1, p) - 1;
                additionL = power(additionL, i, p);
                if(i < k){
                    additionR = power(2, n, p);
                    additionR = power(additionR, k - i - 1, p);
                }
                answer += (additionL * additionR) % p;
            }
            else
            {
                additionL = power(2, n-1, p);
                additionL = power(additionL, i, p);
                if(i < k){
                    additionR = power(2, n-1, p) + 1;
                    additionR = power(additionR, k - i - 1, p);
                }
                answer += (additionL * additionR) % p;
            }
        }
        printf("%lld\n", answer % p);
    }
}