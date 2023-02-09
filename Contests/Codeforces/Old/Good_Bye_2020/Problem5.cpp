#include <bits/stdc++.h>
using namespace std;

long long ipow(long long base, long long exp)
{
    long long result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

long long moduloMultiplication(long long a, 
                            long long b, 
                            long long mod) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 

int main(){
    int t;
    long long mod = 1000000007;
    int NUM = 60;
    long long powersOfTwo[NUM];
    for (int i = 0; i < NUM; i++){
        powersOfTwo[i] = ipow(2, i) % mod;
    }
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++){
        int n;
        scanf("%d", &n);
        long long arr[n];
        for (int i = 0; i < n; i++){
            scanf("%lld", &arr[i]);
        }
        vector<int> distribution(NUM);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < NUM; j++){
                if((arr[i]>>j) & 1){
                    distribution[j]++;
                }
            }
        }
        long long totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            long long sum1 = 0, sum2 = 0;
            for (int j = 0; j < NUM; j++){
                if((arr[i]>>j) & 1){
                    sum1 += (long long)distribution[j] * powersOfTwo[j];
                    sum2 += n * powersOfTwo[j];
                }
                else
                {
                    sum2 += (long long)distribution[j] * powersOfTwo[j];
                }
            }
            sum1 = sum1 % mod;
            sum2 = sum2 % mod;
            totalSum += sum1 * sum2;
            totalSum = totalSum % mod;
        }
        printf("%lld\n", totalSum%mod);
    }
}