#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, T;
        scanf("%d %d", &n, &T);
        vector<pair<int,int>> arr;
        for(int b = 0; b < n; b++){
            int num;
            scanf("%d", &num);
            arr.push_back(make_pair(num, b));
        }
        sort(arr.begin(), arr.end());
        int start = 0, stop = n-1;
        for(int b = 0; b < n-1; b++){
            int sum = arr[b].first + arr[b+1].first;
            if(sum < T){
                start = b;
            }else if(sum > T and stop == n-1){
                stop = b;
            }
        }
        int divide = (start + stop)/2;
        int answer[n];
        for(int b = 0; b < n; b++){
            if(b <= divide){
                answer[arr[b].second] = 0;
            }else{
                answer[arr[b].second] = 1;
            }
        }
        for(int b = 0; b < n; b++){
            printf("%d ", answer[b]);
        }
        printf("\n");

    }
}