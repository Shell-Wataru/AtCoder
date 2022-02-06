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

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

ll patterns(ll N,UnionFind &uf,ll number,vector<vector<bool>> &G){
    // cout << number << endl;
    ll base = 0;
    for(int i = 0;i < N;i++){
        if (uf.same(number,i)){
            base |= 1ll<<i;
        }
    }
    vector<vector<ll>> DP1(N);
    set<ll> masks;
    for (int i = base; i;i = (i-1) & base)
    {
        bool is_ok = true;
        for (int j = 0; j < N; j++)
        {
            if (i & 1ll << j)
            {
                for (int k = j + 1; k < N; k++)
                {

                    if ((i & 1ll << k) && G[j][k])
                    {
                        is_ok = false;
                        break;
                    }
                }
            }
            if (!is_ok)
            {
                break;
            }
        }
        if (is_ok)
        {
            // cout << i << endl;
            masks.insert(i);
            for (int j = 0; j < N; j++)
            {
                if (i & 1ll << j)
                {
                    DP1[j].push_back(i);
                    break;
                }
            }
        }
    }
    vector<vector<map<ll, ll>>> DP2(N + 1, vector<map<ll, ll>>(4));
    for(int i = 0;i < N;i++){
        if (base & 1ll<<i){
            DP2[i][0][0] = 1;
            break;
        }
    }
    // DP2[0][0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        ll j;
        j = 0;
        for (auto p1 : DP2[i][j])
        {
            for (auto s : DP1[i])
            {
                if (!(p1.first & s))
                {
                    ll new_s = p1.first | s;
                    ll new_i = N;
                    for (int k = 0; k < N; k++)
                    {
                        if (!(new_s & 1ll << k) && (base & 1ll<<k))
                        {
                            new_i = k;
                            break;
                        }
                    }
                    DP2[new_i][j + 1][new_s] += p1.second;
                }
            }
        }

        j = 1;
        for (auto p1 : DP2[i][j])
        {
            for (auto s : DP1[i])
            {
                if (!(p1.first & s))
                {
                    ll new_s = p1.first | s;
                    if (masks.find(base & ~new_s) != masks.end()){
                        DP2[N][3][base] += p1.second;
                    }
                    if (new_s == base){
                        DP2[N][2][base] += p1.second;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (auto p : DP2[N][1])
    {
        ans += p.second * 3;
    }
    for (auto p : DP2[N][2])
    {
        ans += p.second * 6;
    }
    for (auto p : DP2[N][3])
    {
        ans += p.second * 6;
    }
    return ans;
}
int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<bool>> G(N, vector<bool>(N, false));
    UnionFind uf(N);
    for (int i = 0; i < M; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        uf.unite(u,v);
        G[u][v] = true;
        G[v][u] = true;
    }
    ll ans = 1;
    for(int i = 0;i < N;i++){
        if (uf.find(i) == i){
            ans *= patterns(N,uf,i,G);
        }
    }
    cout << ans << endl;
    return 0;
}
