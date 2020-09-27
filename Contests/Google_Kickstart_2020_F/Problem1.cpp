#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n, x, withdraw;
        vector<pair<int,int>> answer;
        scanf("%d %d", &n, &x);
        for(int j = 0; j < n; j++){
            scanf("%d", &withdraw);
            answer.push_back(make_pair((withdraw-1)/x, j+1));
        }
        sort(answer.begin(), answer.end());
        printf("Case #%d: ", i+1);
        for(int a = 0; a < answer.size(); a++){
            printf("%d ", answer[a].second);
        }
        printf("\n");
    }
}