#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    int diff = 0;
    for (int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            diff++;
        }else{
            diff--;
        }
        if(diff < 0){
            return false;
        }
    }
    return diff == 0;
}

int main(){
    int t;
    scanf("%d\n", &t);
    for (int k = 0; k < t; k++){
        int n;
        string s;
        cin >> n >> s;
        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '0'){
                zeros++;
            }
        }
        if(zeros%2 == 1){
            printf("NO\n");
            continue;
        }
        int pastOnes = 0, pastZeros = 0;
        string s1 = "", s2 = "";
        for (int i = 0; i < n; i++){
            if(s[i] == '1'){
                if(pastOnes < (n-zeros)/2){
                    s1 += "(";
                    s2 += "(";
                }else{
                    s1 += ")";
                    s2 += ")";
                }
                pastOnes++;
            }else{
                if(pastZeros%2 == 0){
                    s1 += "(";
                    s2 += ")";
                }else{
                    s1 += ")";
                    s2 += "(";
                }
                pastZeros++;
            }
        }
        bool works = (isValid(s1) && isValid(s2));
        if(works){
            cout << "YES" << endl
             << s1 << endl
             << s2 << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}