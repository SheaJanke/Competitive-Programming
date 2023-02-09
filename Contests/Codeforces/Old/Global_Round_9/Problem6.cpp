#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a,b,c, add;
    int lastUsed = 0;
    scanf("%lld %lld %lld", &a, &b, &c);
    cout << "Second" << endl;
    cout.flush();
    fflush(stdout);
    scanf("%lld", &add);
    while(add > 0){
        if(lastUsed == 1){
            if(b+add != a and b+add != c and (b+add)-max(a,c) != max(a,c)-min(a,c)){
                cout << "2" << endl;
                lastUsed = 2;
            }else{
                cout << "3" << endl;
                lastUsed = 3;
            }
        }else if(lastUsed == 2){
            if(a+add != b and a+add != c and (a+add)-max(b,c) != max(b,c)-min(b,c)){
                cout << "1" << endl;
                lastUsed = 1;
            }else{
                cout << "3" << endl;
                lastUsed = 3;
            }
        }else if(lastUsed == 3){
            if(a+add != b and a+add != c and (a+add)-max(b,c) != max(b,c)-min(b,c)){
                cout << "1" << endl;
                lastUsed = 1;
            }else{
                cout << "2" << endl;
                lastUsed = 2;
            }
        }else{
            if(a+add != b and a+add != c and (a+add)-max(b,c) != max(b,c)-min(b,c)){
                cout << "1" << endl;
                lastUsed = 1;
            }else if(b+add != a and b+add != c and (b+add)-max(a,c) != max(a,c)-min(a,c)){
                cout << "2" << endl;
                lastUsed = 2;
            }else{
                cout << "3" << endl;
                lastUsed = 3;
            }
        }
        cout.flush();
        scanf("%lld", &add);
    }
}