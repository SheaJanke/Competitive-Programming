#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
        int n;
        long long p;
        scanf("%d %lld", &n, &p);
        long long answer = 0;
        long long smallest;
        int smallestIndex = 0;
        scanf("%lld", &smallest);
        vector<long long> vals(n);
        vals[0] = smallest;
        for (int i = 1; i < n; i++)
        {
            long long val;
            scanf("%lld", &val);
            vals[i] = val;
            if (val < smallest)
            {
                if(smallest%val == 0){
                    answer += min(val, p) * (i - smallestIndex);
                    answer -= min(smallest, p) * (i - smallestIndex - 1);
                }else{
                    bool works = true;
                    for (int j = i-1; j > smallestIndex; j--)
                    {
                        if(vals[j]%val == 0){
                            if(works){
                                answer += min(val, p);
                                if(j < i-1){
                                    answer -= min(smallest, p);
                                }
                            }
                        }else{
                            works = false;
                        }
                    }
                    if(vals[i-1]%val != 0){
                        answer += p;
                    }
                }
                smallest = val;
            }
            else
            {
                if(val%smallest == 0){
                    answer += min(smallest, p);
                }
                else
                {
                    answer += p;
                    smallest = val;
                }
            }
        }
        printf("%lld\n", answer);
    }
}