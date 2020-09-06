#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n, k, val;
        scanf("%d %d", &n, &k);
        vector<int> xCoords, yCoords;
        for(int b = 0; b < n; b++){
            scanf("%d", &val);
            xCoords.push_back(val);
        }
        for(int b = 0; b < n; b++){
            scanf("%d", &val);
            yCoords.push_back(val);
        }
        sort(xCoords.begin(), xCoords.end());
        int maximumSavedTogether = 0, curSavedTogether = 0;
        int lPointer = 0, rPointer = 0;
        int bestLeft = 0, bestRight = 0;
        for(int rPointer = 0; rPointer < xCoords.size(); rPointer++){
            curSavedTogether++;
            while(xCoords[rPointer] - xCoords[lPointer] > 2*k){
                lPointer++;
                curSavedTogether--;
            }
            maximumSavedTogether = max(maximumSavedTogether, curSavedTogether);
        }
        int maxSavedSingle = 0, curSavedSingle = 0, lPointer = 0;
        for(int rPointer = 0; rPointer < xCoords.size(); rPointer++){
            curSavedSingle++;
            while(xCoords[rPointer] - xCoords[lPointer] > k){
                lPointer++;
                curSavedSingle--;
            }
            if(curSavedSingle > maxSavedSingle){
                
            }
        }


    }
}