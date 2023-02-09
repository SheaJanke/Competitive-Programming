#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        vector<pair<int, int>> answer;
        int curNum = n;
        int arr[n];
        for (int j = 0; j < n; j++){
            arr[j] = j + 1;
        }
        for (int j = n - 1; j >= 3; j--)
        {
            if ((int)ceil((double)curNum / (j - 1)) > (j - 1))
            {
                answer.push_back(make_pair(n, j));
                arr[n - 1] = (int)ceil((double)arr[n - 1] / arr[j-1]);
                curNum = (int)ceil((double)curNum / j);
            }
            while(arr[j-1] != 1){
                answer.push_back(make_pair(j, n));
                arr[j-1] = (int)ceil((double)arr[j-1] / arr[n - 1]);
            }
        }
        while(curNum > 1){
            answer.push_back(make_pair(n, 2));
            curNum = (int)ceil((double)curNum / 2);
            arr[n - 1] = (int)ceil((double)arr[n - 1] / 2);
        }
        printf("%d\n", (int)answer.size());
        for (int j = 0; j < (int)answer.size(); j++){
            printf("%d %d\n", answer[j].first, answer[j].second);
        }
    }
}