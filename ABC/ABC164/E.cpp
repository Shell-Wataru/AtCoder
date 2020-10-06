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
ll BASE_NUM = 1000000007;

const int NONE = -1;

template <typename T>
struct S
{
  long long node, prev;
  T cost;
  S(long long n, T c, long long p) : node(n), cost(c), prev(p) {}
  bool operator>(const S &s) const
  {
    return cost > s.cost;
  }
};

template <typename T>
class Dijkstra
{
  long long n;
  vector<map<long long, T>> G;

public:
  vector<T> minc;
  vector<long long> prev;

  Dijkstra(vector<map<long long, T>> &G) : n(G.size()), G(G), minc(n, NONE), prev(G.size()) {}

  void solve(long long start)
  {
    minc.assign(n, NONE);
    priority_queue<S<T>, vector<S<T>>, greater<S<T>>> pq;
    pq.push(S<T>(start, 0, NONE));
    while (!pq.empty())
    {
      S<T> s = pq.top();
      pq.pop();
      if (minc[s.node] != NONE)
      {
        continue;
      }
      minc[s.node] = s.cost;
      prev[s.node] = s.prev;
      for (auto itr = G[s.node].begin(); itr != G[s.node].end(); ++itr)
      {
        pq.push(S<T>(itr->first, s.cost + itr->second, s.node));
      }
    }
  }

  void print()
  {
      for (int i = 0; i < n; i++)
      {
          cout << i << ":" << minc[i] << endl;
      }
  };
};

int main()
{
  // 整数の入力
  ll N, M, S;
  cin >> N >> M >> S;
  ll MAX_MONEY = 50 * N + 1;
  vector<map<ll, ll>> G(N * MAX_MONEY);
  for (int i = 0; i < M; i++)
  {
    ll u, v, a, b;
    cin >> u >> v >> a >> b;
    u--;
    v--;
    for (int j = 0; j < MAX_MONEY; j++)
    {
      if (j - a >= 0){
        G[u * MAX_MONEY + j][v * MAX_MONEY + j - a] = b;
        G[v * MAX_MONEY + j][u * MAX_MONEY + j - a] = b;
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    ll c, d;
    cin >> c >> d;
    for (int j = 0; j < MAX_MONEY; j++)
    {
      if  (j + c < MAX_MONEY)
      {
        G[i * MAX_MONEY + j][i * MAX_MONEY + j + c] = d;
      }else{
        G[i * MAX_MONEY + j][i * MAX_MONEY +  MAX_MONEY - 1] = d;
      }
    }
  }
  Dijkstra<ll> dickstra(G);
  dickstra.solve(min(S,MAX_MONEY - 1));
  // dickstra.print();
  // cout << MAX_MONEY << endl;
  for (int i = 1; i < N; i++)
  {
    ll min_m = numeric_limits<ll>::max();
    for (int j = 0; j < MAX_MONEY; j++)
    {
      min_m = min(min_m, dickstra.minc[i * MAX_MONEY + j]);
    }
    cout << min_m << endl;
  }
  return 0;
}
