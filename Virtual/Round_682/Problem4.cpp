#include <bits/stdc++.h>
using namespace std;

int find_target(int vals[], int n, int target){
    for(int i = 0; i < n; i++){
        if(vals[i] == target){
            return i;
        }
    }
    return -1;
}

int adjust(int num, int found){
    if(num >= found){
        num++;
    }
    return num;
}

int main(){
    int n;
    scanf("%d", &n);
    int vals[n];
    int total = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &vals[i]);
        total ^= vals[i];
    }
    if(n%2 == 1){
        printf("YES\n");
        printf("%d\n", n-2);
        for(int i = 0; i < n-2; i+=2){
            printf("%d %d %d\n", i+1, i+2, i+3);
        }
        for(int i = 0; i < n-4; i+=2){
            printf("%d %d %d\n", i+1, i+2, n);
        }
    }else{
        int found = find_target(vals, n, total);
        if(found == -1){
            printf("NO\n");
        }else{
            printf("YES\n");
            printf("%d\n", n-3);
            for(int i = 0; i < n-2; i+=2){
                printf("%d %d %d\n", adjust(i+1, found), adjust(i+2,found), adjust(i+3,found));
            }
            for(int i = 0; i < n-4; i+=2){
                printf("%d %d %d\n", adjust(i+1,found), adjust(i+2,found), found);
            }
        }
    }
}