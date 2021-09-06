#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int n;
        scanf("%d", &n);
        vector<int> even, odd;
        for (int i = 0; i < n; i++){
            int val;
            scanf("%d", &val);
            if(val%2 == 0){
                even.push_back(i);
            }else{
                odd.push_back(i);
            }
        }
        int evenSz = even.size();
        int oddSz = odd.size();
        if (abs(evenSz - oddSz) <= 1)
        {
            if(abs(evenSz - oddSz) == 0){
                int startZero = 0;
                int index = 0;
                for (int i = 0; i < n; i+=2){
                    startZero += abs(even[index] - i);
                    index++;
                }
                int startOne = 0;
                index = 0;
                for (int i = 1; i < n; i += 2)
                {
                    startOne += abs(even[index] - i);
                    index++;
                }
                printf("%d\n", min(startZero, startOne));
            }else{
                int answer = 0;
                int index = 0;
                if (evenSz > oddSz)
                {
                    for (int i = 0; i < n; i+=2){
                        answer += abs(even[index] - i);
                        index++;
                    }
                }
                else
                {
                    for (int i = 0; i < n; i+=2){
                        answer += abs(odd[index] - i);
                        index++;
                    }
                }
                printf("%d\n", answer);
            }
        }else{
            printf("-1\n");
        }
    }
}