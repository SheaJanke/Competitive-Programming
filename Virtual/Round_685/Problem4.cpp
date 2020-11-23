#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        long long d, k;
        scanf("%lld %lld", &d, &k);
        long long xAndy = 0;
        while(2 * (xAndy*xAndy) <= d*d){
            xAndy += k;
        }
        xAndy -= k;
        bool Uwins = false;
        if((xAndy*xAndy) + ((xAndy + k) * (xAndy + k)) > d*d){
            Uwins = true;
        }
        if(Uwins){
            printf("Utkarsh\n");
        }else{
            printf("Ashish\n");
        }
    }
}