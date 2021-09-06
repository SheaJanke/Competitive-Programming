#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int z = 0; z < t; z++){
        int n, x;
        scanf("%d %d", &n, &x);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        bool works = true;
        int sum = 0;
        for (int i = 0; i < n; i++){
            if(sum + arr[i] == x){
                if(i == n-1){
                    works = false;
                }else{
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
            sum += arr[i];
        }
        if(works){
            printf("YES\n");
            for (int i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");
        }else{
            printf("NO\n");
        }
    }
}