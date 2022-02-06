#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

ll dfs(vector<vector<ll>> &G,ll current,ll parent,vector<ll> &a,vector<ll> &ans,vector<ll> &DP){
    // cout << current << endl;
    ll index = lower_bound(DP.begin(),DP.end(),a[current]) - DP.begin();
    ll old = DP[index];
    DP[index] = a[current];
    ans[current] = lower_bound(DP.begin(),DP.end(),numeric_limits<ll>::max()) - DP.begin();
    for(auto to:G[current]){
        if (to != parent){
            dfs(G,to,current,a,ans,DP);
        }

    }
    DP[index] = old;
    return 0;
}
int solve()
{
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    vector<ll> a(N);
    for(int i = 0;i < N;i++){
        cin >> a[i];
    }
    for(int i = 0;i < N-1;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    // cout << "!!" << endl;
    vector<ll> ans(N);
    vector<ll> DP(N,numeric_limits<ll>::max());
    dfs(G,0,-1,a,ans,DP);
    for(int i = 0;i < N;i++){
        cout << ans[i] << "\n";
    }
    cout << flush;
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
