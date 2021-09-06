#include <bits/stdc++.h>
using namespace std;

long long getNext(vector<long long> &arr){
    vector<long long> next(10);
    for (int i = 0; i < 9; i++){
        next[i + 1] = arr[i];
    }
    next[0] = arr[9];
    next[1] += arr[9];
    long long total = 0;
    for (int i = 0; i < 10; i++)
    {
        if(next[i] > 1000000007){
            next[i] = next[i] % 1000000007;
        }
        arr[i] = next[i];
        total += arr[i];
    }
    return total;
}

int main(){
    int t;
    scanf("%d", &t);
    vector<vector<long long>> lookup(10, vector<long long>(200005));
    for (int i = 0; i < 10; i++){
        vector<long long> start(10);
        start[i] = 1;
        for (int j = 0; j < 200005; j++){
            lookup[i][j + 1] = getNext(start);
        }
    }
    for (int k = 0; k < t; k++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        vector<long long> arr(10);
        while (n > 0)
        {
            int digit = n % 10;
            arr[digit]++;
            n /= 10;
        }
        long long answer = 0;
        for (int i = 0; i < 10; i++)
        {
            answer += lookup[i][m] * arr[i];
        }
        answer = answer % 1000000007;
        printf("%lld\n", answer);
    }
}