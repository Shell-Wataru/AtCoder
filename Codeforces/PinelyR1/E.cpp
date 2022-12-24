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

template< typename G >
struct LowLink {
  const G &g;
  vector< int > used, ord, low;
  vector< int > articulation;
  vector< pair< int, int > > bridge;

  LowLink(const G &g) : g(g) {}

  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for(auto &to : g[idx]) {
      if(!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if(is_articulation) articulation.push_back(idx);
    return k;
  }

  virtual void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for(int i = 0; i < g.size(); i++) {
      if(!used[i]) k = dfs(i, k, -1);
    }
  }
};

int solve()
{
  ll n;
  cin >> n;
  UnionFind uf(n);
  vector<string> G(n);
  vector<vector<ll>> realG(n);
  vector<ll> edge_counts(n,0);
  for (int i = 0; i < n; i++)
  {
    cin >> G[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (G[i][j] == '1')
      {
        uf.unite(i, j);
        edge_counts[i]++;
        // realG[i].push_back(j);
      }
    }
  }

  if (uf.size(0) == n)
  {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (G[i][j] == '1')
      {
        realG[i].push_back(j);
      }
    }
  }
  LowLink<vector<vector<ll>>> lowlink(realG);
  lowlink.build();
  vector<bool> is_articulation(n,false);
  for(auto a:lowlink.articulation){
    is_articulation[a] = true;
  }
  for (int i = 0; i < n; i++)
  {
    if (uf.size(i) == 1)
    {
      cout << 1 << "\n";
      cout << i + 1 << "\n";
      return 0;
    }
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        continue;
      }
      if (uf.same(i, j) && G[i][j] == '0' && !is_articulation[i])
      {
        cout << 1 << "\n";
        cout << i + 1 << "\n";
        return 0;
      }
    }
  }
  ll min_p_count = numeric_limits<ll>::max();
  ll min_p_count_index = -1;
  for (int i = 0; i < n; i++)
  {
    if (edge_counts[i] < min_p_count)
    {
      min_p_count = edge_counts[i];
      min_p_count_index = i;
    }
  }
  vector<ll> ans_normal;
  for (int j = 0; j < n; j++)
  {
    if (min_p_count_index == j)
    {
      continue;
    }
    if (G[min_p_count_index][j] == '1')
    {
      ans_normal.push_back(j);
    }
  }
  ans_normal.push_back(min_p_count_index);

  ll max_rev_p_count = 0;
  ll max_rev_p_count_index = -1;
  for (int i = 0; i < n; i++)
  {
    ll p_count = n-1-edge_counts[i];
    if (p_count > max_rev_p_count)
    {
      max_rev_p_count = p_count;
      max_rev_p_count_index = i;
    }
  }
  vector<ll> ans_rev;
  for (int j = 0; j < n; j++)
  {
    if (max_rev_p_count_index == j)
    {
      continue;
    }
    if (G[max_rev_p_count_index][j] == '0')
    {
      ans_rev.push_back(j);
    }
  }

  if (ans_normal.size() >= ans_rev.size()){
    swap(ans_normal,ans_rev);
  }
  cout << ans_normal.size() << "\n";
  for(int i = 0;i < ans_normal.size();i++){
    if (i != 0){
      cout << " ";
    }
    cout << ans_normal[i]+1;
  }
  cout << "\n";
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
