#include <bits/stdc++.h>
using namespace std;

vector<int> next_combination(vector<int> maximum, vector<int> current, int pos){
    if(pos == maximum.size()){
        return vector<int>();
    }
    vector<int> next = current;
    if(current[pos] < maximum[pos]){
        next[pos]++;
        return next;
    }else{
        for(int a = pos; a >= 0; a--){
            next[pos] = 0;
        }
        return next_combination(maximum, next, pos+1);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        map<int,int> prime_factors;
        int curDivisor = 2;
        while(curDivisor <= sqrt(n)){
            if(n%curDivisor == 0){
                if(prime_factors.count(curDivisor) == 0){
                    prime_factors[curDivisor] = 1;
                }else{
                    prime_factors[curDivisor]++;
                }
                n/=curDivisor;
            }else{
                curDivisor++;
            }
        }
        if(prime_factors.count(n) == 0){
            prime_factors[n] = 1;
        }else{
            prime_factors[n]++;
        }
        vector<pair<int,int>> factors;
        vector<int> maximums;
        for(auto it = prime_factors.begin(); it != prime_factors.end(); it++){
            factors.push_back(*it);
            maximums.push_back(it->second);
        }
        vector<int> current(maximums.size()), next;
        vector<vector<int>> combinations;
        next = next_combination(maximums, current, 0);
        while(next.size() != 0){
            combinations.push_back(next);
            next = next_combination(maximums, next, 0);
        }
    }
}