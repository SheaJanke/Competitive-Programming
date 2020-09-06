#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        scanf("%d", &n);
        int arr[n];
        vector<int> answer;
        set<int> notIn;
        for(int b = 0; b <= n; b++){
            notIn.emplace(b);
        }
        int wrongCount = 0;
        for(int b = 0; b < n; b++){
            scanf("%d", &arr[b]);
            if(arr[b] != b){
                wrongCount++;
            }
            auto it = notIn.find(arr[b]);
            if(it != notIn.end()){
                notIn.erase(it);
            }
        }
        while(wrongCount > 0){
            int mex = *notIn.begin();
            if(mex != n){
                int prev = arr[mex];
                arr[mex] = mex;
                notIn.erase(mex);
                answer.push_back(mex+1);
                bool stillIn = false;
                for(int b = 0; b < n; b++){
                    if(arr[b] == prev){
                        stillIn = true;
                        break;
                    }
                }
                if(!stillIn){
                    notIn.emplace(prev);
                }
                wrongCount--;
            }else{
                int wrongIndex = -1;
                for(int b = 0; b < n; b++){
                    if(arr[b] != b){
                        wrongIndex = b;
                        break;
                    }
                }
                assert(wrongIndex != -1);
                int prev = arr[wrongIndex];
                arr[wrongIndex] = mex;
                notIn.erase(mex);
                answer.push_back(wrongIndex+1);
                notIn.emplace(prev);
            }
        }
        printf("%ld\n", answer.size());
        for(int b = 0; b < answer.size(); b++){
            printf("%d ", answer[b]);
        }
        printf("\n");
    }
}