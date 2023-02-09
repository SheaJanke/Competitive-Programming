#include <bits/stdc++.h>
using namespace std;

int main(){
    string time;
    cin >> time;
    int add;
    scanf("%d", &add);
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3,2));
    hours = (hours + (minutes + add)/60)%24;
    minutes = (minutes + add)%60;
    printf("%02d:%02d\n", hours, minutes);
}