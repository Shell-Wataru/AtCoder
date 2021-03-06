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
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

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
    ll N, M, R, T;
    cin >> N >> M >> R >> T;
    vector<map<ll, ll>> G(N);
    for (int i = 0; i < M; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a][b] = c;
        G[b][a] = c;
    }
    Dijkstra<ll> dijkstra(G);
    ll counter = 0;
    for (int i = 0; i < N; i++)
    {
        dijkstra.solve(i);
        vector<ll> costs(dijkstra.minc);
        sort(costs.begin(), costs.end());
        for (int j = 0; j < N; j++)
        {
            costs[j] = costs[j] * T;
        }
        for (int j = 1; j < N; j++)
        {
            auto iter_upper = upper_bound(costs.begin(), costs.end(), costs[j] * R / T);
            if (costs.begin() + j < iter_upper){
                counter += costs.end() - iter_upper;
            }else{
                counter += costs.end() - iter_upper - 1;
            }
        }
    }
    cout << counter << endl;
    return 0;
}