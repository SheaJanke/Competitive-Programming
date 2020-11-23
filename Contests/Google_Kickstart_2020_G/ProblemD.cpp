#include <bits/stdc++.h>
using namespace std;

long long getTotal(vector<int> remaining, long long curScore){
    if(remaining.size() == 1){
        return curScore;
    }
    long long answer = 0;
    for(int a = 0; a < remaining.size()-1; a++){
        vector<int> newRemaining;
        for(int b = 0; b < a; b++){
            newRemaining.push_back(remaining[b]);
        }
        long long addScore = remaining[a] + remaining[a+1];
        newRemaining.push_back(addScore);
        for(int b = a+2; b < remaining.size(); b++){
            newRemaining.push_back(remaining[b]);
        }
        answer += getTotal(newRemaining, curScore + addScore);
    }
    return answer;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        vector<int> nums;
        for(int b = 0; b < n; b++){
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }
        double total = getTotal(nums, 0);
        long long divisor = 1;
        for(int b = 1; b < n; b++){
            divisor *= b;
        }
        printf("Case #%d: %f\n", a+1, total/divisor);
    }
}