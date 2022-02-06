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

template <typename T>
struct edge
{
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x)
  {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

int solve()
{
  ll n;
  scanf("%lld", &n);
  UnWeightedGraph g(n);
  UnWeightedGraph rev_g(n);
  for (int i = 0; i < n; i++)
  {
    ll k;
    scanf("%lld", &k);
    for (int j = 0; j < k; j++)
    {
      ll a;
      scanf("%lld", &a);
      a--;
      g[a].push_back(i);
      rev_g[i].push_back(a);
    }
  }
  StronglyConnectedComponents<UnWeightedGraph> scc(g);
  vector<ll> depth(n);
  for (auto components : scc.nodes)
  {
    if (components.size() > 1)
    {
      cout << -1 << "\n";
      return 0;
    }
    for (auto c : components)
    {
      ll max_depth = 1;
      for (auto from : rev_g[c])
      {
        if (from < c)
        {
          max_depth = max(max_depth, depth[from]);
        }
        else
        {
          max_depth = max(max_depth, depth[from] + 1);
        }
      }
      depth[c] = max_depth;
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(ans, depth[i]);
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