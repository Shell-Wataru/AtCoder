#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

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
    ll N, K, L;
    cin >> N >> K >> L;
    vector<pair<ll, ll>> roads(K);
    vector<pair<ll, ll>> rails(L);
    UnionFind uf_roads(N);
    UnionFind uf_rails(N);
    UnionFind uf_all(N);
    map<ll, set<ll>> roads_sets;
    map<ll, set<ll>> rails_sets;
    map<pair<ll, ll>, ll> cache;
    for (int i = 0; i < K; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        roads[i] = {u, v};
        uf_roads.unite(u, v);
    }
    for (int i = 0; i < L; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        rails[i] = {u, v};
        uf_rails.unite(u, v);
    }
    for (int i = 0; i < N; i++)
    {
        roads_sets[uf_roads.find(i)].insert(i);
        rails_sets[uf_rails.find(i)].insert(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (i != 0){
            cout << " ";
        }
        ll a = uf_roads.find(i);
        ll b = uf_rails.find(i);
        if (cache.find({a, b}) == cache.end())
        {
            if (uf_roads.size(i) == 1 || uf_rails.size(i) == 1){
                cache[{a, b}] = 1;
            }else{
                set<ll> result;
                // aとbの積集合を作る
                set_intersection(roads_sets[a].begin(), roads_sets[a].end(),
                                rails_sets[b].begin(), rails_sets[b].end(),
                                std::inserter(result, result.end()));
                cache[{a, b}] = result.size();
            }
        }
        cout << cache[{a, b}];
    }
    cout << "\n";
    return 0;
}

int main()
{
    // ll t;
    // cin >> t;
    // for(int i = 0;i < t;i++){
    solve();
    // }
    cout << flush;
    return 0;
}