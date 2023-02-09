#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int z = 0; z < t; z++){
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);
        map<int, int> left, right;
        for (int i = 0; i < l; i++){
            int val;
            scanf("%d", &val);
            left[val]++;
        }
        for (int i = 0; i < r; i++){
            int val;
            scanf("%d", &val);
            right[val]++;
        }
        int pairsFound = 0;
        for (auto it = left.begin(); it != left.end(); it++)
        {
            if(right[it->first] > 0){
                int subtract = min(right[it->first], it->second);
                pairsFound += subtract;
                right[it->first] -= subtract;
                it->second -= subtract;
            }
        }
        long long answer = 0;
        if(l < r){
            int rightNoPairs = 0;
            for (auto it = right.begin(); it != right.end(); it++){
                if(it->second%2 == 1){
                    rightNoPairs++;
                }
            }
            int leftRemaining = 0;
            for (auto it = left.begin(); it != left.end(); it++){
                leftRemaining += it->second;
            }
            pairsFound += leftRemaining;
            rightNoPairs -= leftRemaining;
            answer = leftRemaining + (n / 2 - pairsFound) + max(0, rightNoPairs/2);
        }
        else
        {
            int leftNoPairs = 0;
            for (auto it = left.begin(); it != left.end(); it++){
                if(it->second%2 == 1){
                    leftNoPairs++;
                }
            }
            int rightRemaining = 0;
            for (auto it = right.begin(); it != right.end(); it++){
                rightRemaining += it->second;
            }
            pairsFound += rightRemaining;
            leftNoPairs -= rightRemaining;
            answer = rightRemaining + (n / 2 - pairsFound) + max(0, leftNoPairs/2);
        }
        printf("%lld\n", answer);
    }
}