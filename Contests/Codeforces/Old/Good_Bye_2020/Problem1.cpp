#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++){
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        unordered_set<int> vals;
        int sz = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++){
                if(vals.find(arr[j] - arr[i]) == vals.end()){
                    sz++;
                    vals.emplace(arr[j] - arr[i]);
                }
            }
        }
        printf("%d\n", sz);
    }
}