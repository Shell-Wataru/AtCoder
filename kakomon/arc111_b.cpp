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

struct UnionFind {
  vector< int > data;
  vector< int > edge_count;

  UnionFind(int sz) {
    data.assign(sz, -1);
    edge_count.assign(sz, 0);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) {
        edge_count[x] += 1;
        return (false);
    }
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    edge_count[x] +=  edge_count[y] + 1;
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


int solve()
{
    ll N;
    cin >> N;
    UnionFind uf(400000);
    for(int i = 0;i < N;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a,b);
    }
    ll ans = 0;
    for(int i = 0;i < 400000;i++){
        if (uf.find(i) ==i){
            ans += min(uf.size(i), uf.edge_count[i]);
        }
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
