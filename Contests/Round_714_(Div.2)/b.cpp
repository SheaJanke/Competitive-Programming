#include <bits/stdc++.h>
using namespace std;

long long mutliplyMod(long long num1, long long num2){
    return (num1 * num2) % (1000000007);
}

int main(){
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
        int n;
        scanf("%d", &n);
        map<int, int> vals;
        int totalAnd = -1;
        for (int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            vals[val]++;
            if(totalAnd == -1){
                totalAnd = val;
            }else{
                totalAnd = totalAnd & val;
            }
        }
        long long ends = mutliplyMod(vals[totalAnd], vals[totalAnd] - 1);
        long long middle = 1;
        for (long long i = 2; i <= n - 2; i++){
            middle = mutliplyMod(middle, i);
        }
        long long answer = mutliplyMod(ends, middle);
        printf("%lld\n", answer);
    }
}