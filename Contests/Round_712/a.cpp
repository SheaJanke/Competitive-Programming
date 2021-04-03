#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int n = s.size();
    for (int i = 0; i < n / 2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    scanf("%d\n", &t);
    for (int k = 0; k < t; k++){
        string s;
        cin >> s;
        int n = s.size();
        if(!isPalindrome(s + "a")){
            cout << "YES" << endl;
            cout << s + "a" << endl;
        }else if(!isPalindrome("a" + s)){
            cout << "YES" << endl;
            cout << "a" + s << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}