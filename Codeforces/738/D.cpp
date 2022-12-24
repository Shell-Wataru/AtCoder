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
  ll n, m1, m2;
  scanf("%lld", &n);
  scanf("%lld", &m1);
  scanf("%lld", &m2);
  UnionFind uf1(n);
  UnionFind uf2(n);
  for (int i = 0; i < m1; i++)
  {
    ll u, v;
    scanf("%lld",&u);
    scanf("%lld",&v);

    u--;
    v--;
    uf1.unite(u, v);
  }
  for (int i = 0; i < m2; i++)
  {
    ll u, v;
    scanf("%lld",&u);
    scanf("%lld",&v);
    u--;
    v--;
    uf2.unite(u, v);
  }
  vector<pair<ll, ll>> answers;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (!uf1.same(i, j) && !uf2.same(i, j))
      {
        answers.push_back({i + 1, j + 1});
        uf1.unite(i, j);
        uf2.unite(i, j);
      }
    }
  }
  cout << answers.size() << "\n";
  for (int i = 0; i < answers.size(); i++)
  {
    cout << answers[i].first << " " << answers[i].second << "\n";
  }
  return 0;
}

int main()
{
  // // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}
