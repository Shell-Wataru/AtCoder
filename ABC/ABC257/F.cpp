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

const ll NONE = numeric_limits<ll>::max()/4;

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

    vector<ll> path(ll last)
    {
        vector<ll> stack;
        stack.push_back(last);
        while (prev[stack.back()] != NONE)
        {
            stack.push_back(prev[stack.back()]);
        }
        reverse(stack.begin(), stack.end());
        return stack;
    };
};


int solve()
{
    ll N,M;
    cin >> N >> M;
    vector<vector<pair<ll,ll>>> G(N);
    vector<bool> teleporter(N,false);
    for(int i = 0;i < M;i++){
      ll u,v;
      cin >> u >> v;
      u--;v--;
      if (u > v){
        swap(u,v);
      }
      if (u == -1){
        teleporter[v] = true;
      }else{
        G[u].push_back({v,1});
        G[v].push_back({u,1});
      }
    }
    Dijkstra<ll> from1(G);
    Dijkstra<ll> fromN(G);
    from1.solve(0);
    fromN.solve(N-1);
    ll from1_nearest_teleporter = numeric_limits<ll>::max()/4;
    ll fromN_nearest_teleporter = numeric_limits<ll>::max()/4;
    for(int i = 0;i < N;i++){
      if (teleporter[i]){
        from1_nearest_teleporter = min(from1_nearest_teleporter,from1.minc[i]);
        fromN_nearest_teleporter = min(fromN_nearest_teleporter,fromN.minc[i]);
      }
    }

    for(int i = 0;i < N;i++){
      if (i != 0){
        cout << " ";
      }
      ll d = min(
        min(from1.minc[N-1],from1.minc[i] + 1 + fromN_nearest_teleporter),
        min(from1_nearest_teleporter + fromN.minc[i] + 1,from1_nearest_teleporter+ 1 + fromN_nearest_teleporter + 1 )
      );
      if (d >= numeric_limits<ll>::max()/4){
        cout << -1;
      }else{
        cout << d;
      }
    }
    cout << endl;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
