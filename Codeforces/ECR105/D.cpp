#include <iostream>
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
ll BASE_NUM = 998244353;


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


int recursive(vector<vector<ll>> &G, vector<ll> candidates, vector<ll> &salaries, vector<pair<ll, ll>> &edges)
{
  // cout << candidates.size() << endl;
  if (candidates.size() == 1)
  {
    return candidates[0] + 1;
  }
  else
  {
    ll max_salary = 0;
    for (auto c : candidates)
    {
      max_salary = max(max_salary, G[candidates[0]][c]);
    }
    salaries.push_back(max_salary);
    ll parent_node = salaries.size();
    UnionFind uf(candidates.size());
    for (size_t i = 0; i < candidates.size(); i++)
    {
      if (uf.size(i) > 1){
        continue;
      }
      for (size_t j = i+1; j < candidates.size(); j++)
      {
        if (G[candidates[i]][candidates[j]] != max_salary){
          uf.unite(i,j);
        }
      }
    }
    map<ll,vector<ll>> groups;
    for(int i = 0;i < candidates.size();i++){
      groups[uf.find(i)].push_back(candidates[i]);
    }
    for(auto &p:groups){
      ll child = recursive(G, p.second, salaries, edges);
      edges.push_back({child, parent_node});
    }
    return parent_node;
  }
}
int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<vector<ll>> G(n, vector<ll>(n, 0));
  vector<ll> candidates(n);
  iota(candidates.begin(), candidates.end(), 0);
  vector<pair<ll, ll>> edges;
  for (int i = 0; i < n; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      scanf("%lld", &G[i][j]);
    }
  }
  vector<ll> salaries(n);
  for (int i = 0; i < n; i++)
  {
    salaries[i] = G[i][i];
  }
  recursive(G,candidates,salaries,edges);
  cout << salaries.size() << "\n";
  for (int i = 0; i < salaries.size(); i++)
  {
    if (i != 0)
    {
      cout << " ";
    }
    cout << salaries[i];
  }
  cout << "\n";
  cout << n + 1 << "\n";
  for (auto &e : edges)
  {
    cout << e.first << " " << e.second << "\n";
  }
  cout << flush;
  return 0;
}

int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  // cout << flush;
  return 0;
}