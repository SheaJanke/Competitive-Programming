#include <bits/stdc++.h>
using namespace std;

long long calcSegCost(int startIndex, int endIndex, int n, int currArr[], long long x, long long k, long long y){
    //printf("SegStart: %d, SegEnd: %d\n", startIndex, endIndex);
    int maxRemove = 0;
    if(startIndex > 0){
        maxRemove = currArr[startIndex-1];
    }
    if(endIndex < n-1){
        maxRemove = max(maxRemove, currArr[endIndex+1]);
    }
    //printf("Max Remove: %d\n", maxRemove);
    int fireballsNeeded = 0;
    int berserksNeeded = 0;
    for(int a = startIndex; a <= endIndex; a++){
        if(currArr[a] > maxRemove){
            fireballsNeeded = 1;
            break;
        }
    }
    //printf("Fireballs Needed: %d\n", fireballsNeeded);
    if(fireballsNeeded * k > endIndex-startIndex+1){
        return -1;
    }else{
        int rem = (endIndex-startIndex+1)-(fireballsNeeded*k);
        if(x < y*k){
            fireballsNeeded += rem/k;
            berserksNeeded += rem%k;
        }else{
            berserksNeeded += rem;
        }
        //printf("SegCost: %lld\n", fireballsNeeded * x + berserksNeeded * y);
        return fireballsNeeded * x + berserksNeeded * y;
    }
}


int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    long long x,k,y;
    scanf("%lld %lld %lld", &x, &k, &y);
    int currentArr[n], targetArr[m];
    bool takeOut[n];
    for(int a = 0; a < n; a++){
        scanf("%d", &currentArr[a]);
    }
    for(int a = 0; a < m; a++){
        scanf("%d", &targetArr[a]);
    }
    int targetPointer = 0;
    for(int a = 0; a < n; a++){
        if(currentArr[a] == targetArr[targetPointer]){
            targetPointer++;
            takeOut[a] = false;
        }else{
            takeOut[a] = true;
        }
        if(targetPointer == m){
            for(int b = a+1; b < n; b++){
                takeOut[b] = true;
            }
            break;
        }
    }
    if(targetPointer == m){
        long long answer = 0;
        bool started = false;
        int startIndex;
        for(int a = 0; a < n; a++){
            if(takeOut[a] == true){
                if(!started){
                    started = true;
                    startIndex = a;
                }
            }else{
                if(started){
                    started = false;
                    long long segtotal = calcSegCost(startIndex, a-1, n, currentArr, x, k, y);
                    if(segtotal == -1){
                        answer = -1;
                        break;
                    }else{
                        answer += segtotal;
                    }
                }
            }
        }
        if(started){
            long long segtotal = calcSegCost(startIndex, n-1, n, currentArr, x, k, y);
            if(segtotal == -1){
                answer = -1;
            }else{
                answer += segtotal;
            }
        }
        printf("%lld\n", answer);
    }else{
        printf("-1\n");
    }
}