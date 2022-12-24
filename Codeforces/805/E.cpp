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
  ll n;
  cin >> n;
  UnionFind uf(n);
  vector<ll> counts(n);
  for(int i = 0;i < n;i++){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    uf.unite(a,b);
    counts[a]++;
    counts[b]++;
  }
  for(int i = 0;i < n;i++){
    if (counts[i] >= 3){
        cout << "No\n";
        return 0;
    }
    if (uf.find(i) == i && uf.size(i) % 2 == 1){
        cout << "No\n";
        return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
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
