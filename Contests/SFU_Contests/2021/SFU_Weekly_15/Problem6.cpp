#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        string num;
        cin >> num;
        int total = 0;
        for(int b = 0; b < num.size(); b++){
            int dig;
            if(b%2 == 0){
                dig = ((int)num[num.size()-1-b]-48); 
            }else{
                dig = ((int)num[num.size()-1-b]-48) * 2; 
            }
            total += dig/10 + dig%10;
        }
        if(total%10 == 0){
            printf("PASS\n");
        }else{
            printf("FAIL\n");
        }
    }
}