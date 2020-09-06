#include <bits/stdc++.h>
using namespace std;

int min_cost(string str, int target){
    if(str.length() == 1){
        if(str[0] == target){
            return 0;
        }else{
            return 1;
        }
    }else{
        int leftcost = 0, rightcost = 0;
        for(int a = 0; a < str.length()/2; a++){
            if(str[a] != target){
                leftcost++;
            }
        }
        leftcost += min_cost(str.substr(str.length()/2, str.length()/2), target+1);
        for(int a = str.length()/2; a < str.length(); a++){
            if(str[a] != target){
                rightcost++;
            }
        }
        rightcost += min_cost(str.substr(0, str.length()/2), target+1);
        return min(leftcost, rightcost);
    }
}


int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n;
        scanf("%d", &n);
        string str;
        cin >> str;
        printf("%d\n", min_cost(str, 97));
    }
}