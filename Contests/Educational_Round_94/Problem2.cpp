#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        long long p, f, cnts, cntw, s, w;
        scanf("%lld %lld", &p, &f);
        scanf("%lld %lld", &cnts, &cntw);
        scanf("%lld %lld", &s, &w);
        int maximum = 0;
        if(s < w){
            int pTakesS = min(p/s, cnts);
            int pTakesW = min((p - pTakesS*s)/w, cntw);
            while(pTakesW < cntw and pTakesS > 0 and (pTakesS-1) * s + (pTakesW+1) * w <= p){
                pTakesW++;
                pTakesS--;
            }
            int fTakesS = min(f/s, cnts - pTakesS);
            int fTakesW = min((f - fTakesS*s)/w, cntw - pTakesW);
            maximum = pTakesS + pTakesW + fTakesS + fTakesW;
            fTakesS = min(f/s, cnts);
            fTakesW = min((f - fTakesS*s)/w, cntw);
            while(fTakesW < cntw and fTakesS > 0 and (fTakesS-1) * s + (fTakesW+1) * w <= f){
                fTakesW++;
                fTakesS--;
            }
            pTakesS = min(p/s, cnts - fTakesS);
            pTakesW = min((p - pTakesS*s)/w, cntw - fTakesW);
            maximum = max(maximum, pTakesS + pTakesW + fTakesS + fTakesW);
            printf("%d\n", maximum);
        }else{
            int pTakesW = min(p/w, cntw);
            int pTakesS = min((p - pTakesW*w)/s, cnts);
            while(pTakesS < cnts and pTakesW > 0 and (pTakesW-1) * w + (pTakesS+1) * s <= p){
                pTakesS++;
                pTakesW--;
            }
            int fTakesW = min(f/w, cntw - pTakesW);
            int fTakesS = min((f - fTakesW*w)/s, cnts - pTakesS);
            maximum = pTakesS + pTakesW + fTakesS + fTakesW;
            
            fTakesW = min(f/w, cntw);
            fTakesS = min((f - fTakesW*w)/s, cnts);
            while(fTakesS < cnts and fTakesW > 0 and (fTakesW-1) * w + (fTakesS+1) * s <= f){
                fTakesS++;
                fTakesW--;
            }
            pTakesW = min(p/w, cntw - fTakesW);
            pTakesS = min((p - pTakesW*w)/s, cnts - fTakesS);
            maximum = max(maximum, pTakesS + pTakesW + fTakesS + fTakesW);

            printf("%d\n", maximum);
        }
    }
}