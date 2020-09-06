#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    long long n;
    for(int a = 0; a < t; a++){
        scanf("%lld", &n);
        int two = 0;
        int three = 0;
        while(n%2 == 0){
            n = n/2;
            two++;
        }
        while(n%3 == 0){
            n = n/3;
            three++;
        }
        if(n == 1 and three >= two){
            printf("%d\n", three+(three-two));
        }else{
            printf("-1\n");
        }
    }
}