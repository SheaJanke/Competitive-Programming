#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &vals, int target){
    for (int i = 0; i < vals.size(); i++){
        if(vals[i] == target){
            return i;
        }
    }
    assert(false);
    return -1;
}

int main(){
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        int n;
        scanf("%d", &n);
        vector<int> vals(n);
        bool works = true;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vals[i]);
            if((i+1)%2 != vals[i]%2){
                works = false;
            }
        }
        if(works){
            vector<int> answer;
            for (int i = 1; i < n; i += 2)
            {
                int indexI = find(vals, i);
                answer.push_back(indexI + 1);
                reverse(vals.begin(), vals.begin() + indexI + 1);
                int indexNext = find(vals, i + 1);
                answer.push_back(indexNext);
                reverse(vals.begin(), vals.begin() + indexNext);
                answer.push_back(indexNext + 2);
                reverse(vals.begin(), vals.begin() + indexNext + 2);
                answer.push_back(3);
                reverse(vals.begin(), vals.begin() + 3);
                answer.push_back(n - i + 1);
                reverse(vals.begin(), vals.begin() + n - i + 1);
            }
            answer.push_back(n);
            reverse(vals.begin(), vals.begin() + n);
            printf("%d\n", (int)answer.size());
            for (int i = 0; i < answer.size(); i++)
            {
                printf("%d ", answer[i]);
            }
            printf("\n");
            // for (int i = 0; i < n; i++){
            //     printf("%d ", vals[i]);
            // }
            // printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
}