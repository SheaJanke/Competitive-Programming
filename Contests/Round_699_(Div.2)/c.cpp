#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int k = 0; k < t; k++){
        int n, m;
        scanf("%d %d", &n, &m);
        int a[n];
        int b[n];
        int c[m];
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++){
            scanf("%d", &b[i]);
        }
        map<int, int> got;
        for (int i = 0; i < m; i++){
            scanf("%d", &c[i]);
            got[c[i]]++;
        }
        int lastColorIn = -1;
        for (int i = 0; i < n; i++){
            if(b[i] == c[m-1]){
                lastColorIn = i;
            }
        }
        map<int, set<int>> needed;
        for (int i = 0; i < n; i++)
        {
            if(a[i] != b[i]){
                needed[b[i]].emplace(i);
            }
        }
        bool works = true;
        for (int i = 0; i < n; i++){
            if(got[i] < needed[i].size()){
                works = false;
            }
        }
        if (works && lastColorIn != -1)
        {
            printf("YES\n");
            for (int i = 0; i < m-1; i++)
            {
                if(needed[c[i]].empty()){
                    printf("%d ", lastColorIn + 1);
                }
                else{
                    printf("%d ", *needed[c[i]].begin() + 1);
                    needed[c[i]].erase(needed[c[i]].begin());
                }
            }
            printf("%d\n", lastColorIn+1);
        }
        else
        {
            printf("NO\n");
        }
    }
}