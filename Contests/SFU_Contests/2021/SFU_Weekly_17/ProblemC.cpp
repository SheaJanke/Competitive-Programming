#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, num;
    scanf("%d %d", &n, &m);
    int answer = 0;
    for(int a = 0; a < n; a++){
        int rowMin = pow(10,9);
        for(int b = 0; b < m; b++){
            scanf("%d", &num);
            rowMin = min(num, rowMin);
        }
        answer = max(answer, rowMin);
    }
    printf("%d\n", answer);
}