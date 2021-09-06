#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int n, q;
        scanf("%d %d", &n, &q);
        string s;
        cin >> s;
        vector<int> overallSum(n+1);
        int curSum = 0;
        for (int i = 0; i < n; i++)
        {
            int val = 1;
            if(s[i] == '-'){
                val = -1;
            }
            if(i%2 == 1){
                val *= -1;
            }
            curSum += val;
            overallSum[i+1] = curSum;
            //printf("%d ", curSum);
        }
        //printf("\n");
        for (int i = 0; i < q; i++)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            int answer;
            if((r-l+1)%2 == 0){
                answer = 2;
            }else{
                answer = 1;
            }
            if(overallSum[r] - overallSum[l - 1] == 0){
                answer = 0;
            }
            printf("%d\n", answer);
        }
    }
}