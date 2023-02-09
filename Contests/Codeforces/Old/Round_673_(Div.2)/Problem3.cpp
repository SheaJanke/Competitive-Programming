#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        vector<pair<int,int>> arr;
        for(int b = 0; b < n; b++){
            int num;
            scanf("%d", &num);
            arr.push_back(make_pair(num, b));
        }
        sort(arr.begin(), arr.end());
        vector<int> answer(n+1);
        int lastNum = -1, lastNumPos = -1, curMin = 0, minFound = n+1;
        for(int b = 0; b < n; b++){
            if(arr[b].first != lastNum){
                if(lastNum != -1){
                    curMin = max(n-lastNumPos, curMin);
                    if(curMin < minFound){
                        answer[curMin] = lastNum;
                        minFound = curMin;
                    }
                }
                lastNum = arr[b].first;
                lastNumPos = arr[b].second;
                curMin = lastNumPos+1;
            }else{
                curMin = max(curMin, arr[b].second - lastNumPos);
                lastNumPos = arr[b].second;
            }
        }
        curMin = max(n-lastNumPos, curMin);
        if(curMin < minFound){
            answer[curMin] = lastNum;
            minFound = curMin;
        }
        int curNum = -1;
        for(int b = 1; b <= n; b++){
            if(answer[b] != 0){
                curNum = answer[b];
            }
            printf("%d ", curNum);
        }
        printf("\n");
    }
}