#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; j++){
        int n, k;
        scanf("%d %d", &n, &k);
        int arr[n];
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        bool done = false;
        vector<int> answer;
        while(!done){
            int curPos = 0;
            while (curPos < n-1){
                if(arr[curPos+1] > arr[curPos]){
                    arr[curPos]++;
                    break;
                }else{
                    curPos++;
                }
            }
            if(curPos == n-1){
                answer.push_back(-2);
                done = true;
            }
            else
            {
                answer.push_back(curPos);
            }
        }
        if(k-1 < answer.size()){
            printf("%d\n", answer[k - 1] + 1);
        }else{
            printf("-1\n");
        }
    }
}