#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int xorArr[n-1];
    map<int, set<int>> vals;
    pair<int,int> same;
    bool foundSame = false;
    for(int i = 1; i <= n-1; i++){
        cout << "XOR " << 1 << " " << i+1 << endl;
        int response;
        cin >> response;
        if(response == -1){
            return 0;
        }
        xorArr[i-1] = response;
        if(!foundSame and response == 0){
            same.first = 1;
            same.second = i+1;
            foundSame = true;
        }else if(!foundSame and !vals[response].empty()){
            same.first = *vals[response].begin();
            same.second = i+1;
            foundSame = true;
        }
        vals[response].emplace(i+1);
    }
    if(foundSame){
        int realValue;
        cout << "OR " << same.first << " " << same.second << endl;
        cin >> realValue;
        int valueOne = realValue ^ xorArr[same.second-2];
        cout << "! " << valueOne << " ";
        for(int i = 0; i < n-1; i++){
            cout << (valueOne ^ xorArr[i]) << " ";
        }
        cout << endl;
    }else{
        int oneDiff = 0;
        while(xorArr[oneDiff] != 1){
            oneDiff++;
        }
        int andOne;
        cout << "AND 1 " << oneDiff+2 << endl;
        cin >> andOne;
        int sameParity = 0;
        while(xorArr[sameParity]%2 != 0){
            sameParity++;
        }
        int orSameParity;
        cout << "OR 1 " << sameParity+2 << endl;
        cin >> orSameParity;
        int valueOne;
        if(orSameParity%2 == 0){
            valueOne = andOne;
        }else{
            valueOne = andOne + 1;
        }
        cout << "! " << valueOne << " ";
        for(int i = 0; i < n-1; i++){
            cout << (valueOne ^ xorArr[i]) << " ";
        }
        cout << endl;
    }
}