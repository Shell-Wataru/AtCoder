#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

int dfs(vector<vector<pair<ll,ll>>>  &G,map<ll,ll> &xor_count,ll current,ll parent,ll value){
    xor_count[value]++;
    for(auto to:G[current]){
        if (to.first != parent){
            dfs(G,xor_count,to.first,current,to.second ^ value);
        }
    }
    return 0;
}
int solve()
{

    ll n,x;
    scanf("%lld",&n);
    scanf("%lld",&x);
    vector<vector<pair<ll,ll>>>  G(n);
    for(int i = 0;i < n-1;i++){
        ll u,v,c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].push_back({v,c});
        G[v].push_back({u,c});
    }
    map<ll,ll> xor_count;
    dfs(G,xor_count,0,-1,0);
    ll ans = 0;
    for(auto p:xor_count){
        // cout << p.first << ":" << p.second << endl;
        ll target = x^p.first;
        if (target > p.first && xor_count.find(target) != xor_count.end()){
            ans += p.second * xor_count[target];
        }else if(target == p.first){
            ans += p.second * (p.second -1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}