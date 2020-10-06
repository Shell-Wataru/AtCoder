#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

bool dfs(vector<vector<ll>> &G,vector<bool> &visited, ll current, ll destination){
    visited[current] = true;
    if (current == destination){
        return true;
    }
    ll can_go = false;
    for(auto &to:G[current]){
        if (!visited[to]){
            can_go = can_go || dfs(G,visited,to,destination);
        }
    }
    return can_go;
}

int solve()
{
    ll n;
    scanf("%lld", &n);
    string a,b;
    cin >> a;
    cin >> b;
    set<pair<ll,ll>,greater<pair<ll,ll>>> data;
    vector<vector<ll>> G(26);
    for(int i = 0; i < n;i++){
        data.emplace(b[i] - 'a',a[i] - 'a');
    }
    ll total = 0;
    bool can = true;
    for(auto &p:data){
        vector<bool> visited(26,false);
        if (dfs(G,visited,p.second,p.first)){
            G[p.second].push_back(p.first);
        }else{
            total++;
        }
    }
    if (can){
        cout << total << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
