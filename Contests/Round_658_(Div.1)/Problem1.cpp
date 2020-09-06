#include <bits/stdc++.h>
using namespace std;

string flip_operation(string str, int prefix, int n){
    string newSection = "";
    for(int a = prefix-1; a >= 0; a--){
        if(str[a] == '0'){
            newSection += "1";
        }else{
            newSection += "0";
        }
    }
    return newSection + str.substr(prefix, n-prefix);
}


int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        string initial, target;
        vector<int> answer;
        int n;
        scanf("%d", &n);
        cin >> initial >> target;
        for(int b = n-1; b >= 0; b--){
            if(initial[b] != target[b]){
                if(initial[0] != target[b]){
                    answer.push_back(b+1);
                }else{
                    answer.push_back(1);
                    answer.push_back(b+1);
                }
                initial = flip_operation(initial, b+1, n);
            }
        }
        printf("%ld ", answer.size());
        for(int b = 0; b < answer.size(); b++){
            printf("%d ", answer[b]);
        }
        printf("\n");
    }
}