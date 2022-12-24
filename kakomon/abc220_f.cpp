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

int dfs1(int current, int parent, vector<vector<ll>> &G, vector<ll> &total_distances,vector<ll> &node_counts)
{
    ll total_distance = 0;
    ll node_count = 1;
    for (auto &to : G[current])
    {
        if (to != parent)
        {
            dfs1(to, current, G, total_distances,node_counts);
            total_distance += total_distances[to] + node_counts[to];
            node_count += node_counts[to];
        }
    }
    total_distances[current] = total_distance;
    node_counts[current] = node_count;
    return 0;
}

int dfs2(int current, int parent, ll parent_total_distance, ll parent_node_counts, vector<vector<ll>> &G, vector<ll> &total_distances,vector<ll> &node_counts, vector<ll> &answer_disntances)
{
    ll n = G.size();
    answer_disntances[current] = total_distances[current] + parent_total_distance + parent_node_counts;
    for (auto &to : G[current])
    {
        if (to != parent)
        {
            dfs2(to, current, answer_disntances[current] - total_distances[to] - node_counts[to],n - node_counts[to],G,total_distances,node_counts,answer_disntances);
        }
    }
    return 0;
}

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<vector<ll>> G(n);
  for(int i = 0;i < n-1;i++){
      ll a,b;
      cin >> a >> b;
      a--;
      b--;
      G[a].push_back(b);
      G[b].push_back(a);
  }
  vector<ll> total_distances(n);
  vector<ll> node_counts(n);
  vector<ll> answer_counts(n);
  dfs1(0,-1,G,total_distances,node_counts);
  dfs2(0,-1,0,0,G,total_distances,node_counts,answer_counts);
  for(int i = 0;i < n;i++){
      cout << answer_counts[i] << "\n";
  }
  return 0;
}

int main()
{
  // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}