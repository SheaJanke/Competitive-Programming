#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x1,y1,x2,y2;
    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    int n;
    scanf("%d", &n);
    int answer = 0;
    for(int i = 0; i < n; i++){
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long diff1 = a * x1 + b * y1 + c;
        long long diff2 = a * x2 + b * y2 + c;
        if(diff1 < 0 and diff2 > 0 or diff1 > 0 and diff2 < 0){
            answer++;
        }
    }
    printf("%d\n", answer);
}