#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int add = 1;
    string s = "";
    while(s.size() < n){
        s += to_string(add);
        add++;
    }
    cout << s[n-1] << endl;
}