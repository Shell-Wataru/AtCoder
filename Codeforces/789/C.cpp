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
  scanf("%lld", &n);
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> rev_a(n);
  vector<ll> rev_b(n);
  UnionFind uf(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    a[i]--;
    rev_a[a[i]] = i;
  }
  for(int i = 0;i < n;i++){
    scanf("%lld",&b[i]);;
    b[i]--;
    rev_b[b[i]] = i;
  }
  for(int i = 0;i < n;i++){
    uf.unite(rev_a[i],rev_b[i]);
  }
  unordered_map<ll,ll> diffrent_counts;
  for(int i = 0;i < n;i++){
    if (a[i] != b[i]){
      diffrent_counts[uf.find(i)]++;
    }
  }
  ll ans = 0;
  ll different_count = 0;
  for(auto p:diffrent_counts){
    // cout << p.second << endl;
    different_count += p.second/2;
  }
  for(int i = 0;i < different_count;i++){
    ans += 2 *(n-i) - 2 * (i+1);
  }
  cout << ans << "\n";
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
