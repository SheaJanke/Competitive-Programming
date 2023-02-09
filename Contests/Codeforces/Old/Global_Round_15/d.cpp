#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int z = 0; z < t; z++){
        int n;
        cin >> n;
        vector<int> vals(n);
        for (int i = 0; i < n; i++){
            cin >> vals[i];
        }
        if(n == 1){
            if(vals[0] == 0){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
            continue;
        }
        bool works = false;
        for (int i = 0; i < n; i++){
            int bitmask = (int)(pow(2, n) + 0.5);
            //printf("bitmask: %d\n", bitmask);
            for (int j = 0; j < bitmask; j++)
            {
                for (int k = j; k; k=(k-1)&j){
                    int sum = 0;
                    for (int l = 0; l < n; l++){
                        int add = 0;
                        if (l != i && (j >> l) & 1){
                            add = vals[l];
                        }
                        if (l != i && (k >> l) & 1){
                            add = -add;
                        }
                        sum += add;
                    }
                    if(abs(vals[i]) == abs(sum)){
                        //printf("sum:%d\n", sum);
                        works = true;
                    }
                }
            }
        }
        if(works){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}