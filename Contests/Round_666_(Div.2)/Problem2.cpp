#include <bits/stdc++.h>
using namespace std;

long long nthRootSearch(long long minimum, long long maximum, long long num, int n){
    if(minimum+1 >= maximum){
        return minimum;
    }
    long long middle = (maximum + minimum)/2;
    long long cur = 1;
    for(int a = 0; a < n; a++){
        cur *= middle;
        if(cur > num){
            return nthRootSearch(minimum, middle, num, n);
        }
    }
    return nthRootSearch(middle, maximum, num, n);
}

long long getCost(long long power, long long seq[], int n){
    long long curCost = 0, curPower = 1;
    for(int a = 0; a < n; a++){
        curCost += abs(seq[a] - curPower);
        curPower *= power;
        if(curCost > pow(10,16)){
            return pow(10,16);
        }
    }
    return curCost;
}


int main(){
    int n;
    scanf("%d", &n);
    long long seq[n];
    long long curCost = 0;
    for(int a = 0; a < n; a++){
        scanf("%lld", &seq[a]);
        curCost += seq[a]-1;
    }
    sort(seq, seq+n);
    long long low = nthRootSearch(1, 10000000000, seq[n-1], n-1);
    printf("%lld\n", min(getCost(low, seq, n), getCost(low+1, seq, n)));

}