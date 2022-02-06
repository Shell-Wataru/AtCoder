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

int solve()
{
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    vector<ll> a(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        // u--;
        // v--;
        uf.unite(u, v);
    }
    map<ll, vector<ll>> group_costs;
    vector<pair<ll,ll>> costs;
    for (int i = 0; i < N; i++)
    {
        group_costs[uf.find(i)].push_back(a[i]);
    }
    vector<ll> musts;
    vector<ll> candidates;
    for (auto p : group_costs)
    {
        sort(p.second.begin(), p.second.end());
        musts.push_back(p.second[0]);
        for(int i = 1;i < p.second.size();i++){
            candidates.push_back(p.second[i]);
        }
    }
    // cout << group_costs.size() << endl;
    if (group_costs.size() == 1){
        // cout << "~";
        cout << 0 << endl ;
        return 0;
    }
    if (musts.size() + candidates.size() < 2*group_costs.size() -2){
        cout << "Impossible" << endl;
        return 0;
    }
    ll ans = 0;
    sort(candidates.begin(),candidates.end());
    for(auto c:musts){
        ans += c;
    }
    for(int i = 0;i < group_costs.size()-2;i++){
        ans += candidates[i];
    }
    cout << ans << endl;
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
