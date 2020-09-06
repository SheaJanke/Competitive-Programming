#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int diff = abs(a-b) + 9;
        printf("%d\n", diff/10);
    }
}