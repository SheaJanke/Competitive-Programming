#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, m;
        scanf("%d %d", &n, &m);
        long long arr[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%lld", &arr[i][j]);
            }
        }
        long long answer = 0;
        for(int i = 0; i < (n+1)/2; i++){
            for(int j = 0; j < (m+1)/2; j++){
                vector<long long> vals;
                vals.push_back(arr[i][j]);
                vals.push_back(arr[i][m-j-1]);
                vals.push_back(arr[n-i-1][j]);
                vals.push_back(arr[n-i-1][m-j-1]);
                sort(vals.begin(), vals.end());
                long long total = vals[2];
                if(n-i-1 == i and m-j-1 == j){
                    answer += abs(arr[i][j] - total);
                }else if(n-i-1 == i){
                    answer += abs(arr[i][j] - total);
                    answer += abs(arr[i][m-j-1] - total);
                }else if(m-j-1 == j){
                    answer += abs(arr[i][j] - total);
                    answer += abs(arr[n-i-1][j] - total); 
                }else{
                    answer += abs(arr[i][j] - total);
                    answer += abs(arr[i][m-j-1] - total);
                    answer += abs(arr[n-i-1][j] - total);   
                    answer += abs(arr[n-i-1][m-j-1] - total);
                }
            }
        }
        printf("%lld\n", answer);
    }
}