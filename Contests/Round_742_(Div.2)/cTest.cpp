#include <bits/stdc++.h>
using namespace std;

int getSum(int a, int b){
    int answer = 0;
    int mod = 1;
    while(a / mod > 0 || b / mod > 0){
        int digitA = (a / mod) % 10;
        int digitB = (b / mod) % 10;
        if(digitA + digitB > 0){
            answer += 100 * mod;
        }
        answer += ((digitA + digitB) % 10) * mod;
        mod *= 10;
    }
    return answer;
}

int main(){
    int n;
    scanf("%d", &n);
    int answer = 0;
    for (int i = 1; i < n; i++)
    {
        if(getSum(i, n-i) == n){
            answer++;
        }
    }
    printf("%d\n", answer);
}