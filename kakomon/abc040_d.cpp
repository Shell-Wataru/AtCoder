#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

//https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
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

int solve()
{
    ll N,M,Q;
    cin >> N >> M;
    vector<vector<ll>> edges(M,vector<ll>(3));
    for(int i = 0;i < M;i++){
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--;
        edges[i][2]--;
    }
    cin >> Q;
    vector<vector<ll>> queries(Q,vector<ll>(3));
    vector<ll> ans(Q);
    for(int i = 0;i < Q;i++){
        cin >> queries[i][1] >> queries[i][0];
        queries[i][1]--;
        queries[i][2] = i;
    }
    sort(edges.rbegin(),edges.rend());
    sort(queries.rbegin(),queries.rend());
    ll edges_index = 0;
    UnionFind uf(N);
    for(int i = 0;i < Q;i++){
        while(edges_index < M && queries[i][0] < edges[edges_index][0]){
            uf.unite(edges[edges_index][1],edges[edges_index][2]);
            edges_index++;
        }
        ans[queries[i][2]] = uf.size(queries[i][1]);
    }
    for(int i = 0;i < Q;i++){
        cout << ans[i] << endl;
    }
    return 0;
}

int main()
{
    //   // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}