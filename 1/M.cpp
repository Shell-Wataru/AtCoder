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

ll BASE_NUM = 1e9 + 7;
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
  vector<map<long long,T>> G;

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
    ll N,M;
    cin >> N >> M;
    vector<map<ll,ll>> G(N);
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    ll s,K;
    cin >> s;
    s--;
    cin >> K;
    vector<ll> Ks;
    // cout << "aa" << endl;
    for(int i = 0;i < K;i++){
        ll k;
        cin >> k;
        k--;
        // cout << k << endl;
        Ks.push_back(k);
    }
    Ks.push_back(s);
    sort(Ks.begin(),Ks.end());
    Dijkstra<ll> d(G);
    vector<vector<ll>> Distances(K+1,vector<ll>(K+1,0));
    for(int i = 0;i < K+1;i++){
        d.solve(Ks[i]);
        for(int j = 0;j < K+1;j++){
            Distances[i][j] = d.minc[Ks[j]];
            // cout << Distances[i][j] << ",";
        }
        // cout << endl;
    }
    // cout << "!!" << endl;
    vector<vector<ll>> DP(K+1,vector<ll>(1<<(K+1),BASE_NUM));
    ll s_index = lower_bound(Ks.begin(),Ks.end(),s) - Ks.begin();
    // cout << "S" << s_index << endl;
    DP[s_index][1<<s_index] = 0;
    for(int i = 1; i < (1<<(K+1));i++){
        for(int j = 0;j < K + 1;j++){
            if (i & (1<<j)){
                for(int k = 0;k < K + 1;k++){
                    DP[j][i] = min(DP[j][i], Distances[k][j] + DP[k][i - (1<<j)]);
                }
            }
        }
    }
    ll min_cost = BASE_NUM;
    for(int i = 0;i < K + 1;i++){
        min_cost =min(min_cost,DP[i][(1<<(K+1)) - 1]);
    }
    cout << min_cost << endl;
    return 0;
}