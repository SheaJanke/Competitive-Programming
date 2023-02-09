#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; j++){
        int n, k;
        scanf("%d %d", &n, &k);
        if (k > (n-1) / 2){
            printf("-1\n");
        }else{
            int peaks = 0;
            for (int i = 1; i <= n; i++){
                if(i%2 == 0 && peaks < k){
                    printf("%d ", n - peaks);
                    peaks++;
                }
                else
                {
                    printf("%d ", n - k - i + peaks + 1);
                }
            }
            printf("\n");
        }
    }
}