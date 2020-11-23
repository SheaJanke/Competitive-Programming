#include <bits/stdc++.h>
using namespace std;

int main(){
    double ax, ay, bx, by, tx, ty, totalDistance = 0;
    scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &tx, &ty);
    int n;
    scanf("%d", &n);
    vector<pair<double,int>> aDiff, bDiff;
    for(int i = 0; i < n; i++){
        double x,y;
        scanf("%lf %lf", &x, &y);
        double trashDistance = sqrt(pow(x-tx,2) + pow(y-ty,2));
        double aDistance = sqrt(pow(x-ax,2) + pow(y-ay,2));
        double bDistance = sqrt(pow(x-bx,2) + pow(y-by,2));
        totalDistance += 2 * trashDistance;
        aDiff.push_back(make_pair(aDistance-trashDistance, i));
        bDiff.push_back(make_pair(bDistance-trashDistance, i));
    }
    sort(aDiff.begin(), aDiff.end());
    sort(bDiff.begin(), bDiff.end());
    double minA = aDiff[0].first, minB = bDiff[0].first;
    int minAi = aDiff[0].second, minBi = bDiff[0].second;
    if(minA < minB){
        totalDistance += minA;
        if(n > 1){
            if(minAi != minBi){
                if(minB < 0){
                    totalDistance += minB;
                }
            }else{
                if(bDiff[1].first < 0){
                    totalDistance -= minA;
                    double option1 = aDiff[1].first + bDiff[0].first;
                    double option2 = aDiff[0].first + bDiff[1].first;
                    totalDistance += min(option1, option2);
                }
            }
        }

    }else{
        totalDistance += minB;
        if(n > 1){
            if(minAi != minBi){
                if(minA < 0){
                    totalDistance += minA;
                }
            }else{
                if(aDiff[1].first < 0){
                    totalDistance -= minB;
                    double option1 = aDiff[1].first + bDiff[0].first;
                    double option2 = aDiff[0].first + bDiff[1].first;
                    totalDistance += min(option1, option2);
                }
            }
        }
    }
    cout.precision(10);
    cout << totalDistance << endl;
}