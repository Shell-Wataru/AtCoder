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
#include <set>
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
  ll N;
  cin >> N;
  vector<ll> P(N);
  vector<ll> invP(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &P[i]);
    P[i]--;
    invP[P[i]] = i;
  }
  ll M;
  cin >> M;
  vector<vector<ll>> G(N);
  UnionFind uf(N);
  vector<vector<ll>> parents(N, vector<ll>(N, -1));
  vector<vector<ll>> D(N, vector<ll>(N, numeric_limits<ll>::max() / 2));
  map<pair<ll, ll>, ll> edge_numbers;
  for (int i = 0; i < M; i++)
  {
    ll a, b;
    scanf("%lld", &a);
    scanf("%lld", &b);
    a--;
    b--;
    if (uf.unite(a,b)){
      G[a].push_back(b);
      G[b].push_back(a);
      D[a][b] = 1;
      D[b][a] = 1;
    }
    edge_numbers[{a, b}] = i;
    edge_numbers[{b, a}] = i;
  }
  for (int i = 0; i < N; i++)
  {
    D[i][i] = 0;
    queue<ll> q;
    q.push(i);
    while (!q.empty())
    {
      ll current = q.front();
      q.pop();
      for (auto to : G[current])
      {
        if (parents[i][to] == -1 && to != i)
        {
          parents[i][to] = current;
          D[i][to] = D[i][current] + 1;
          q.push(to);
        }
      }
    }
  }
  vector<ll> operations;
  // for(int i = 0;i < N;i++){
  //   cout <<i << ":" << invP[i] << endl;
  // }
  while (true)
  {
    ll maximum = 0;
    ll i = -1;
    for (int j = 0; j < N; j++)
    {
      if (D[j][invP[j]] > maximum)
      {
        maximum = D[j][invP[j]];
        i = j;
      }
    }
    if (i == -1)
    {
      break;
    }
    while (P[i] != i)
    {
      if (D[i][invP[i]] == numeric_limits<ll>::max() / 2)
      {
        cout << -1 << endl;
        return 0;
      }
      ll to = parents[i][invP[i]];
      swap(P[invP[i]], P[to]);
      // cout << "swap" <<  invP[i] << "," <<  to  << endl;
      operations.push_back(edge_numbers[{invP[i], to}]);
      invP[P[invP[i]]] = invP[i];
      invP[i] = to;
      // for(int k = 0;k < N;k++){
      //   cout <<k << ":" << invP[k] << endl;
      // }
      // for(int k = 0;k < N;k++){
      //   cout <<k << ":" << P[k] << endl;
      // }
    }
  }

  // for (int k = 0; k < N; k++)
  // {
  //   cout << k << ":" << invP[k] << endl;
  // }
  // for (int k = 0; k < N; k++)
  // {
  //   cout << k << ":" << P[k] << endl;
  // }

  cout << operations.size() << endl;
  for (int i = 0; i < operations.size(); i++)
  {
    if (i != 0)
    {
      cout << " ";
    }
    cout << operations[i] + 1;
  }
  cout << endl;
  return 0;
}
