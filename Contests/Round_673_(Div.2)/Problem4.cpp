#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        int arr[n];
        int total = 0;
        for(int b = 0; b < n; b++){
            scanf("%d", &arr[b]);
            total += arr[b];
        }
        bool possible = (total%n == 0);
        if(!possible){
            printf("-1\n");
            continue;
        }
        int target = total/n;
        vector<tuple<int,int,int>> answer;
        for(int b = 1; b < n; b++){
            int times = arr[b]/(b+1);
            answer.push_back(make_tuple(b, 0, times * (b+1)));
            arr[0] += times * (b+1);
            arr[b] -= times * (b+1);
        }
        for(int b = 1; b < n; b++){
            if(arr[b] > target){
                int add = b + target - arr[a];
                if(arr[0] >= add){
                    answer.push_back(make_tuple(1, b+1, add));
                    answer.push_back(make_tuple(b+1, 1, 1));
                }else if(arr[0] >= (b+1)-arr[b]){
                    answer.push_back(make_tuple(1, b+1, (b+1)-arr[b]));
                    answer.push_back(make_tuple(b+1, 1, 1));
                    answer.push_back(make_tuple(1, b+1, target));
                }else{
                    possible = false;
                }
            }else if(arr[b] < target){
                answer.push_back(make_tuple(1, b+1, target-arr[b]));
            }
        }
        if(possible and answer.size() <= 3 * n){
            printf("%ld\n", answer.size());
            for(int b = 0; b < answer.size(); b++){
                printf("%d %d %d\n", get<0>(answer[b]), get<1>(answer[b]), get<2>(answer[b]));
            }
        }else{
            printf("-1\n");
        }
    }
}