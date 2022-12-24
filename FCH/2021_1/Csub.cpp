#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <numeric>
using namespace std;
using ll = long long;

vector<ll> vs(vector<ll> &a){
    stack<ll> s;
    vector<ll> ans;
    for(auto v:a){
        while(!s.empty() && s.top() < v ){
            s.pop();
        }
        s.push(v);
        ans.push_back(s.size());
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll T;
    vector<ll> a(5);
    iota(a.begin(),a.end(),1);
    map<vector<ll>,ll> counts;
    do{
        for(auto v:a){
            cout << v << ",";
        }
        cout << ":";
        for(auto v:vs(a)){
            cout << v << ",";
        }
        cout << endl;
        counts[vs(a)]++;
    }while(next_permutation(a.begin(),a.end()));
    for(auto p:counts){
        for(auto v:p.first){
   v        cout << v << ",";
        }
        cout << ":" << p.second;
        cout << endl;
    }
    return 0;
}