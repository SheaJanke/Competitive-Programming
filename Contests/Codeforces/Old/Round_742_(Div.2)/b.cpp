#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> allXOR(3e5 + 7);
    int cur = 0;
    for (int i = 0; i < 3e5 + 7; i++){
        cur = cur ^ i;
        allXOR[i] = cur;
    }
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int a, b;
        scanf("%d %d", &a, &b);
        if (allXOR[a - 1] == b)
        {
            printf("%d\n", a);
        }
        else if ((allXOR[a - 1] ^ b) == a)
        {
            printf("%d\n", a + 2);
        }
        else
        {
            printf("%d\n", a + 1);
        }
    }
}