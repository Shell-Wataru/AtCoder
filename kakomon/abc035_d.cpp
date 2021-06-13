#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;

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


int main()
{
    ll N,M,T;
    cin >> N >> M >> T;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<vector<pair<ll,ll>>> G(N);
    vector<vector<pair<ll,ll>>> revG(N);
    for (size_t i = 0; i < M; i++)
    {
        ll u,v,c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].push_back({v,c});
        revG[v].push_back({u,c});
    }
    Dijkstra<ll> d(G);
    Dijkstra<ll> revd(revG);
    d.solve(0);
    revd.solve(0);
    ll ans = 0;
    // for(int i = 0;i < N;i++){
    //     cout << d.minc[i]
    // }
    for(int i = 0;i < N;i++){
        if (d.minc[i] != NONE && revd.minc[i] != NONE){
            ans = max(ans, (T-  d.minc[i] - revd.minc[i])*A[i]);
        }
    }
    cout << ans << endl;
   return 0;
}