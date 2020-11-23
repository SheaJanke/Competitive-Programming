#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        map<int,int> Avals, Bvals;
        int n, k;
        scanf("%d %d", &n, &k);
        string a, b;
        cin >> a >> b;
        for(int j = 0; j < n; j++){
            Avals[a[j]]++;
            Bvals[b[j]]++;
        }
        bool works = true;
        int Atotal = 0, Btotal = 0;
        for(int j = 97; j <= 122; j++){
            //printf("A:%d B:%d\n", Avals[j], Bvals[j]);
            int diff = Avals[j] - Bvals[j];
            Atotal += Avals[j];
            Btotal += Bvals[j];
            if(Btotal > Atotal or diff%k != 0){
                works = false;
                break;
            }
        }
        if(works){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }
}