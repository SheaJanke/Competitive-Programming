#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int x1, y1, z1, x2, y2, z2;
        scanf("%d %d %d", &x1, &y1, &z1);
        scanf("%d %d %d", &x2, &y2, &z2);
        int answer = 0;
        answer  += 2 * min(z1, y2);
        answer -= 2 * max(0, z2-(x1 + z1-min(z1, y2)));
        printf("%d\n", answer);
    }
}