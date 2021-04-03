#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++){
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for(int i = 1; i < n; i++){
            if(arr[i-1] >= arr[i]){
                arr[i]++;
            }
        }
        unordered_set<int> diff;
        int sz = 0;
        for (int i = 0; i < n; i++)
        {
            if(diff.find(arr[i]) == diff.end()){
                sz++;
                diff.emplace(arr[i]);
            }
        }
        printf("%d\n", sz);
    }
}