#include <bits/stdc++.h>
using namespace std;

int getAnswer(vector<int> &digits){
    // printf("digits: ");
    // for (int i = 0; i < digits.size(); i++){
    //     printf("%d ", digits[i]);
    // }
    // printf("\n");
    if (digits.empty())
    {
        return 0;
    }
    if(digits[0] == 0){
        vector<int> newDigits;
        for (int i = 1; i < digits.size(); i++){
            newDigits.push_back(digits[i]);
        }
        return getAnswer(newDigits);
    }
    int answer = 1;
    for (int i = 0; i < digits.size(); i++){
        if(digits[i] < 10){
            answer *= digits[i] + 1;
        }else{
            if(digits[i] > 18){
                answer = 0;
            }else{
                answer *= (19 - digits[i]);
            }
        }
    }
    if(digits.size() > 2){
        vector<int> newDigits;
        for (int i = 1; i < digits.size(); i++){
            newDigits.push_back(digits[i]);
        }
        newDigits[1] += 10;
        //printf("digits[0]: %d, %d\n", digits[0], min(digits[0], 19 - digits[0]));
        digits[0]--;
        if (digits[0] < 10)
        {
            answer += (digits[0]+1) * getAnswer(newDigits);
        }
        else
        {
            answer += (19 - digits[0]) * getAnswer(newDigits);
        }
    }
    return answer;
}

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        vector<int> digits;
        for (int j = 0; j < s.size(); j++){
            digits.push_back(s[j] - '0');
        }
        printf("%d\n", getAnswer(digits) - 2);
    }
}