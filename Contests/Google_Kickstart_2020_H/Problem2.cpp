#include <bits/stdc++.h>
using namespace std;

long long power(long long n, int i){
    long long answer = 1;
    for(int j = 0; j < i; j++){
        answer *= n;
    }
    return answer;
}

long long getDigitAt(long long n, int index){
    return (n/power(10,index))%10;
}

long long boringLessThan(long long n){
    long long answer = 0;
    for(int i = 1; i < to_string(n).size(); i++){
        answer += power(5, i);
    }
    int maxIndex = (int)to_string(n).size() - 1;
    for(int i = maxIndex; i >= 0; i--){
        if((maxIndex-i)%2 == 0){
            if(i != 0){
                answer += power(5,i) * (getDigitAt(n,i) / 2);
            }else{
                answer += power(5,i) * ((getDigitAt(n,i)+1) / 2);
            }
            if(getDigitAt(n,i)%2 == 0){
                break;
            }
        }else{
            if(i != 0){
               answer += power(5,i) * ((getDigitAt(n,i)+1) / 2); 
            }else{
                answer += power(5,i) * ((getDigitAt(n,i)+2) / 2);
            }
            if(getDigitAt(n,i)%2 != 0){
                break;
            }
        }
    }
    return answer;
}


int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        long long L,R;
        scanf("%lld %lld", &L, &R);
        printf("Case #%d: %lld\n", i+1, boringLessThan(R) - boringLessThan(L-1));
    }
}