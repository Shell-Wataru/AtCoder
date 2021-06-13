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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

#include <iostream>
#include <vector>
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


int main()
{
    // 整数の入力
    ll n,m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<pair<ll,ll>> edges(m);
    vector<ll> answers(m);
    for(int i = 0;i < m;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        edges[i] = {u,v};
    }
    reverse(edges.begin(),edges.end());
    ll ans = n*(n-1)/2;
    for(int i = 0;i < m;i++){
        ll u = edges[i].first;
        ll v = edges[i].second;
        answers[i] = ans;
        if (uf.same(u,v)){

        }else{
            ll u_size = uf.size(u);
            ll v_size = uf.size(v);
            ans -= u_size * v_size;
            uf.unite(u,v);
        }
    }
    reverse(answers.begin(),answers.end());
    for (size_t i = 0; i < m; i++)
    {
        cout << answers[i] << endl;
    }

    return 0;
}