#include <bits/stdc++.h>
using namespace std;

void reduceFraction(vector<int> &val)
{
    int d;
    d = __gcd(val[0], val[1]);
  
    val[0] /= d;
    val[1] /= d;

    d = __gcd(val[2], val[3]);
  
    val[2] /= d;
    val[3] /= d;
}

int main(){
    int n;
    scanf("%d", &n);
    priority_queue<pair<double, int>> q;
    vector<vector<int>> orig;
    unordered_set<int> used;
    map<vector<int>, queue<int>> vals;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        orig.push_back({a, b, c, d});
        q.push({((double)c/d)/((double)a/b), i});
        vector<int> option1 = {a, b, c, d};
        option1[0] += option1[1];
        reduceFraction(option1);
        vals[option1].emplace(i);
        vector<int> option2 = {a, b, c, d};
        option2[2] += option2[3];
        reduceFraction(option2);
        vals[option2].emplace(i);
    }
    vector <pair<int, int>> answer;
    while (!q.empty())
    {
        int index = q.top().second;
        vector<int> val = orig[index];
        q.pop();
        if(used.find(index) != used.end()){
            continue;
        }
        vector<int> val1 = val;
        val1[2] += val1[3];
        reduceFraction(val1);
        if(!vals[val1].empty()){
            while(!vals[val1].empty()){
                int otherIndex = vals[val1].front();
                vals[val1].pop();
                if(used.find(otherIndex) == used.end() && index != otherIndex){
                    answer.push_back({index, otherIndex});
                    used.emplace(index);
                    used.emplace(otherIndex);
                    break;
                }
            }
        }else{
            val1 = val;
            val1[0] += val1[1];
            reduceFraction(val1);
            while(!vals[val1].empty()){
                int otherIndex = vals[val1].front();
                vals[val1].pop();
                if(used.find(otherIndex) == used.end() && index != otherIndex){
                    answer.push_back({index, otherIndex});
                    used.emplace(index);
                    used.emplace(otherIndex);
                    break;
                }
            }
        }
    }
    printf("%d\n", (int)answer.size());
    for (int i = 0; i < answer.size(); i++){
        printf("%d %d\n", answer[i].first + 1, answer[i].second + 1);
    }
}