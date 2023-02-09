#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        string str;
        int n;
        scanf("%d", &n);
        cin >> str;
        bool hasZero = false;
        if(str[n-1] == '0'){
            hasZero = true;
        }
        for(int b = 0; b < n; b++){
            if(hasZero){
                printf("0");
            }else{
                printf("1");
            }
        }
        printf("\n");
    }
}