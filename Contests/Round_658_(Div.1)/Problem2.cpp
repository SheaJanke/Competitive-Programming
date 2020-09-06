#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        n *= 2;
        int arr[n];
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
        }
        vector<int> sizes;
        int count = 0, max = arr[0];
        for(int j = 0; j < n; j++){
            if(arr[j] <= max){
                count++;
            }else{
                sizes.push_back(count);
                max = arr[j];
                count = 1;
            }
        }
        unordered_set<int> sums;
        bool works = false;
        for(int j = 0; j < sizes.size(); j++){
            for(auto it = sums.begin(); it != sums.end(); it++){
                if((*it) + sizes[j] <= n/2){
                    sums.insert((*it) + sizes[j]);
                }
            }
            sums.insert(sizes[j]);
            if(sums.find(n/2) != sums.end()){
                works = true;
                break;
            }
        }
        if(works){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }
}