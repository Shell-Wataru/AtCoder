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
  vector<vector<pair<long long, T>>> G;

public:
  vector<T> minc;
  vector<long long> prev;

  Dijkstra(vector<vector<pair<long long, T>>> &G) : n(G.size()), G(G), minc(n, NONE), prev(G.size()) {}

  void solve(long long start)
  {
    minc.assign(n, NONE);
    queue<S<T>> pq;
    pq.push(S<T>(start, 0, NONE));
    while (!pq.empty())
    {
      S<T> s = pq.front();
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
    vector<vector<pair<ll,ll>>> G(N);
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back({v,1});
        G[v].push_back({u,1});
    }
    ll K;
    cin >> K;
    vector<ll> C(K);
    for(int i = 0;i < K;i++){
        cin >> C[i];
        C[i]--;
    }
    Dijkstra<ll> d(G);
    vector<vector<ll>> Distances(K,vector<ll>(K,0));
    for(int i = 0;i < K;i++){
        d.solve(C[i]);
        // cout << C[i] << ":";
        // for(int j = 0;j < N;j++){
        //     cout << d.minc[i] << ",";
        // }
        // cout << endl;
        for(int j = 0;j < K;j++){
            Distances[i][j] = d.minc[C[j]];
        }
    }
    // for(int i = 0;i < K;i++){
    //     for(int j = 0;j < K;j++){
    //         cout << Distances[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    vector<vector<ll>> DP(K,vector<ll>(1ll<<K,BASE_NUM));
    for(int i = 0;i < K;i++){
        DP[i][1ll<<i] = 0;
    }

    for(int i = 1; i < (1<<K);i++){
        for(int j = 0;j < K;j++){
            if (i & (1<<j)){
                for(int k = 0;k < K;k++){
                    if (!(i & 1ll<<k)){
                        if (Distances[k][j] != NONE){
                            DP[k][i | 1ll<<k] = min(DP[k][i | 1ll<<k], Distances[k][j] + DP[j][i]);
                        }
                    }

                }
            }
        }
    }
    ll min_cost = BASE_NUM;
    for(int i = 0;i < K;i++){
        min_cost =min(min_cost,DP[i][(1<<K) - 1]);
    }
    if (min_cost == BASE_NUM){
        cout << -1 << endl;
    }else{
        cout << min_cost + 1<< endl;
    }

    return 0;
}