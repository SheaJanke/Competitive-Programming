#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        int n = s.size();
        if (n % 2 == 1)
        {
            printf("NO\n");
        }
        else
        {
            if(s[0] == ')' || s[n-1] == '('){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }
}