#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <list>
using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

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
    int n,p;
    scanf("%d", &n);
    scanf("%d", &p);
    vector<ll> a(n);
    for(int i = 0; i < n;i++){
      scanf("%lld",&a[i]);
    }
    priority_queue<pair<ll,ll>> q;
    for (size_t i = 0; i < n; i++)
    {
      q.push({-a[i],i});
    }
    ll ans = 0;
    UnionFind uf(n);
    while(!q.empty()){
      auto node = q.top();
      q.pop();
      node.first = -node.first;
      if (node.first < p){
        for(int i = node.second + 1; i < n;i++){
          if (a[i] % node.first == 0 && uf.unite(node.second,i)){
            ans += node.first;
          }else{
            break;
          }
        }

        for(int i = node.second - 1; i >= 0;i--){
          if (a[i] % node.first == 0 && uf.unite(node.second,i)){
            ans += node.first;
          }else{
            break;
          }
        }
      }
    }
    for(int i = 0; i < n-1;i++){
      if (uf.unite(i,i+1)){
        ans += p;
      }
    }
    cout << ans << "\n";
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
    cout << flush;
    return 0;
}
