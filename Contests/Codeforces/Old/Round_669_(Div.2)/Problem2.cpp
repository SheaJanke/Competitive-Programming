#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        vector<int> nums, answer;
        for(int a = 0; a < n; a++){
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end());
        int curGCD = nums.back();
        int divide = 2;
        nums.pop_back();
        answer.push_back(curGCD);
        while(curGCD > 1){
            int removed = 0;
            for(int a = 0; a < nums.size() - removed; a++){
                if(nums[a] % curGCD == 0){
                    answer.push_back(nums[a]);
                    nums.erase(nums.begin()+a);
                    removed++;
                    a--;
                }
            }
            while(curGCD % divide != 0){
                divide++;
            }
            curGCD /= divide;
        }
        answer.insert(answer.end(), nums.begin(), nums.end());
        for(int a = 0; a < answer.size(); a++){
            printf("%d ", answer[a]);
        }
        printf("\n");
        
    }
}