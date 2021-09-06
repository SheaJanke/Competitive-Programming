#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<bool> primes(100000, true);
    vector<int> primeNums;
    for (int i = 2; i < 100000; i++){
        if(primes[i]){
            primeNums.push_back(i);
            for (int j = 2*i; j < 100000; j+=i){
                primes[j] = false;
            }
        }
    }
    int t;
    scanf("%d", &t);
    for(int z = 0; z < t; z++){
        int n;
        scanf("%d", &n);
        map<int, int> factors;
        for (int i = 0; i < (int)primeNums.size(); i++){
            while(n%primeNums[i] == 0){
                factors[primeNums[i]]++;
                n /= primeNums[i];
            }
        }
        bool works = true;
        if (n != 1)
        {
            works = false;
        }else{
            if(factors[2] == 0){
                works = false;
            }
            for (auto it = factors.begin(); it != factors.end(); it++){
                if(it->first != 2 && it->second%2 != 0){
                    works = false;
                }
            }
        }
        if(works){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}