#include <bits/stdc++.h>
using namespace std;

pair<int,int> calculateDistance(long long x[], long long y[], double d){
    double absDistance = 0, distance = 0;
    double centerX, centerY;
    if((x[1] + x[2])%2 == (y[1] + y[2])%2){
        centerX = (double)(x[1] + x[2])/2;
        centerY = (double)(y[1] + y[2])/2;
    }else{
        centerX = (double)(x[1] + x[2])/2;
        centerY = (double)(y[1] + y[2] + 1)/2;
    }
    if((x[1] + x[2])%2 == 1){
        d += 0.5;
    }
    absDistance += abs(centerX-d-x[0]);
    absDistance += abs(centerX-d-x[1]);
    absDistance += abs(centerX+d-x[2]);
    absDistance += abs(centerX+d-x[3]);
    distance += centerX-d-x[0];
    distance += centerX-d-x[1];
    distance += x[2]-(centerX-d);
    distance += x[3]-(centerX-d);
    absDistance += abs(centerY-d-y[0]);
    absDistance += abs(centerY-d-y[1]);
    absDistance += abs(centerY+d-y[2]);
    absDistance += abs(centerY+d-y[3]);
    distance += centerY-d-y[0];
    distance += centerY-d-y[1];
    distance += y[2]-(centerY-d);
    distance += y[3]-(centerY-d);
    return make_pair((int)round(absDistance), (int)round(distance));
}

int binSearch(long long x[], long long y[], int l, int r){
    if(l == r){
        return l;
    }
    int mid = (l+r)/2;
    if(calculateDistance(x, y, (double)mid).second > 0){
        return binSearch(x,y,l,mid);
    }else{
        return binSearch(x,y,mid+1,r);
    }

}


int main(){
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; k++){
        long long x[4], y[4];
        for(int i = 0; i < 4; i++){
            scanf("%lld %lld", &x[i], &y[i]);
        }
        sort(x, x+4);
        sort(y, y+4);
        int approxD = binSearch(x,y,0,pow(10,9));
        int minimum = calculateDistance(x,y,approxD).first;
        for(int i = -2; i <= 2; i++){
            if(approxD + i >= 0){
                minimum = min(minimum, calculateDistance(x,y,approxD+i).first);
            }
        }
        printf("%d\n", minimum);
    }
}