#include <bits/stdc++.h>
using namespace std;

int sumDigits(long long num){
    int count = 0;
    while(num > 0){
        count += num%10;
        num /= 10;
    }
    return count;
}


int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        long long n;
        int s;
        scanf("%lld %d", &n, &s);
        if(sumDigits(n) <= s){
            printf("0\n");
        }else{
            stack<int> digits;
            long long num = n;
            while(num > 0){
                digits.push(num%10);
                num /= 10;
            }
            int curDigSum = 1;
            long long curNum = 0;
            while(!digits.empty()){
                int dig = digits.top();
                digits.pop();
                if(curDigSum + dig <= s){
                    curNum *= 10;
                    curNum += dig;
                    curDigSum += dig;
                }else{
                    break;
                }
            }
            if(curNum == 0){
                curNum = 1;
            }else{
                curNum += 1;
            }
            while(curNum < n){
                curNum *= 10;
            }   
            printf("%lld\n", curNum - n);
            
        }



    }
}