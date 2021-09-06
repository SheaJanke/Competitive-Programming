#include <bits/stdc++.h>
using namespace std;

bool getAnswer(string &num, int k, int cur, bool free, set<char> &used, vector<char> &answer){
    if(used.size() > k){
        return false;
    }
    if(cur >= num.size()){
        return true;
    }
    if(free){
        set<char> newUsed(used);
        if (used.size() == k)
        {
            answer[cur] = *used.begin();
        }
        else
        {
            answer[cur] = '0';
            newUsed.emplace('0');
        }
        return getAnswer(num, k, cur + 1, free, newUsed, answer);
    }
    for (char i = num[cur]; i <= '9'; i++){
        set<char> newUsed(used);
        newUsed.emplace(i);
        answer[cur] = i;
        bool works = false;
        if (i == num[cur])
        {
            works = getAnswer(num, k, cur + 1, false, newUsed, answer);
        }
        else
        {
            works = getAnswer(num, k, cur + 1, true, newUsed, answer);
        }
        if(works){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        string num;
        int k;
        cin >> num >> k;
        int n = num.size();
        vector<char> answer(n);
        set<char> used;
        getAnswer(num, k, 0, false, used, answer);
        for (int i = 0; i < n; i++){
            printf("%c", answer[i]);
        }
        printf("\n");
    }
}