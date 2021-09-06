#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for (int z = 0; z < t; z++){
        string s;
        cin >> s;
        int n = s.size();
        set<char> seen;
        vector<char> order;
        map<char, int> chars;
        for (int i = n - 1; i >= 0; i--)
        {
            if(seen.find(s[i]) == seen.end()){
                order.push_back(s[i]);
                seen.emplace(s[i]);
            }
            chars[s[i]]++;
        }
        reverse(order.begin(), order.end());
        bool works = true;
        int initialSize = 0;
        for (int i = 0; i < order.size(); i++)
        {
            if(chars[order[i]] % (i+1) != 0){
                works = false;
            }
            chars[order[i]] /= (i + 1);
            initialSize += chars[order[i]];
        }
        string cur = s.substr(0, initialSize);
        string generated = cur;
        for (int i = 0; i < order.size(); i++){
            string next = "";
            for (int j = 0; j < cur.size(); j++){
                if(cur[j] != order[i]){
                    next.push_back(cur[j]);
                }
            }
            cur = next;
            generated.append(next);
        }
        if(works && (generated == s)){
            string orderString = "";
            for (int i = 0; i < order.size(); i++){
                orderString.push_back(order[i]);
            }
            cout << s.substr(0, initialSize) << " " << orderString << endl;
        }else{
            cout << "-1" << endl;
        }
    }
}