#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<long long> a(n), b(n), sums(n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    long long cur = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &b[i]);
        cur += b[i] * a[i];
        sums[i] = cur;
    }
    long long answer = cur;
    for (int i = 0; i < n; i++){
        int j = 1;
        long long reversed = a[i] * b[i];
        while (i - j >= 0 && i + j < n)
        {
            reversed += a[i - j] * b[i + j];
            reversed += a[i + j] * b[i - j];
            long long curAnswer = reversed;
            if(i - j - 1 >= 0){
                curAnswer += sums[i - j - 1];
            }
            curAnswer += (cur - sums[i + j]);
            answer = max(answer, curAnswer);
            j++;
        }
    }
    for (int i = 0; i < n - 1; i++){
        int j = 0;
        long long reversed = 0;
        while(i - j >= 0 && i + 1 + j < n){
            reversed += a[i - j] * b[i + 1 + j];
            reversed += a[i + 1 + j] * b[i - j];
            long long curAnswer = reversed;
            if(i - j - 1 >= 0){
                curAnswer += sums[i - j - 1];
            }
            curAnswer += (cur - sums[i + j + 1]);
            answer = max(answer, curAnswer);
            j++;
        }
    }
    printf("%lld\n", answer);
}