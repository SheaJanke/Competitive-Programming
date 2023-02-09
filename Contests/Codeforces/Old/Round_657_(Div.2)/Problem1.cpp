#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int a = 0; a < t; a++){
        int n; 
        scanf("%d", &n);
        string str, target = "abacaba";
        cin >> str;
        int worksIndex = -1;
        int soloCount = 0;
        for(int b = 0; b <= n-7; b++){
            bool solo = true, works = true;
            for(int c = 0; c < 7; c++){
                if(target[c] != str[b+c]){
                    if(str[b+c] != '?'){
                        works = false;
                    }
                    solo = false;
                }
            }
            if(works){
                if(b >= 4){
                    works = false;
                    for(int c = -4; c < 0; c++){
                        if(str[b+c] != target[c+4]){
                            works = true;
                            break;
                        }
                    }
                }
                if(works and n >= b + 11){
                    works = false;
                    for(int c = 7; c < 11; c++){
                        if(str[b+c] != target[c-4]){
                            works = true;
                            break;
                        }
                    }
                }
            }
            if(solo){
                soloCount++;
            }else if(works){
                worksIndex = b;
            }
        }
        if(soloCount > 1){
            printf("NO\n");
        }else if(soloCount == 1){
            printf("YES\n");
            replace(str.begin(), str.end(), '?', 'd');
            cout << str << endl;
        }else{
            if(worksIndex != -1){
                printf("YES\n");
                replace(str.begin(), str.end(), '?', 'd');
                cout << str.substr(0, worksIndex) << target << str.substr(worksIndex + 7, n-(worksIndex+7)) << endl;
            }else{
                printf("NO\n");
            }
        }
    }
}