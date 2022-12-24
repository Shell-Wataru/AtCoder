#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    bool same(int x, int y)
    {
        x = find(x), y = find(y);
        return x == y;
    }
    int find(int k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k)
    {
        return (-data[find(k)]);
    }
};

ll dfs(vector<vector<pair<ll, ll>>> &G,ll current, ll parent,ll w, vector<vector<bool>> &have_even, ll digit){
    if (w == 0){
        return 0;
    }else if (have_even[digit][current]){
        return 0;
    }
    have_even[digit][current] = true;
    for(auto e:G[current]){
        ll to = e.first;
        ll next_w = e.second;
        dfs(G,to,current,next_w & w,have_even,digit);
    }
    return 0;
}

int solve()
{
    ll n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<vector<pair<ll, ll>>> G(n);
    vector<vector<bool>> have_even(30,vector<bool>(n, false));
    vector<vector<ll>> edges(m);
    vector<UnionFind> ufs(30,UnionFind(n));
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        scanf("%lld", &u);
        scanf("%lld", &v);
        scanf("%lld", &w);
        u--;
        v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        for(int j = 0;j < 30;j++){
            if (w & 1ll<<j){
                ufs[j].unite(u,v);
            }
        }
        edges[i] = {u,v,w};
    }
    for(auto e:edges){
        if (e[2] % 2 == 0){
            for(int i = 1;i < 30;i++){
                dfs(G,e[0],-1,e[2] & 1ll<<i,have_even,i);
            }

        }
    }
    // for(int i = 0;i < n;i++){
    //     bool ddd = false;
    //     for(int j = 0;j < 30;j++){
    //         ddd = ddd || have_even[j][i];
    //     }
    //     cout << i << ":" << ddd << endl;
    // }
    ll q;
    scanf("%lld",&q);
    while(q--){
        ll u,v;
        scanf("%lld",&u);
        scanf("%lld",&v);
        u--;v--;
        ll ans = 2;
        for(int i = 0;i < 30;i++){
            if (ufs[i].same(u,v)){
                ans = min(ans,0ll);
            }
        }
        for(int i = 0;i < 30;i++){
            if (have_even[i][u]){
                ans = min(ans,1ll);
            }
        }
        cout << ans << "\n";
    }
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
    cout << flush;
    return 0;
}
