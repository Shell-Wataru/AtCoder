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
    // 整数の入力
    ll N, M;
    cin >> N >> M;
    ll sz = 1;
    while (sz < N)
    {
        sz <<= 1;
    }
    // cout << sz << endl;
    vector<vector<pair<ll, ll>>> G(3 * sz + 2 * M);
    for (int i = sz - 1; i > 0; i--)
    {
        if (2 * i >= sz)
        {
            G[i].emplace_back(2 * i + sz, 0);
            G[i].emplace_back(2 * i + 1 + sz,0);
        }
        else
        {
            G[i].emplace_back(2 * i,0);
            G[i].emplace_back(2 * i + 1,0);
        }
    }
    for (int i = sz - 1; i > 0; i--)
    {
        G[2 * i + sz].emplace_back(i + sz,0);
        G[2 * i + 1 + sz].emplace_back(i + sz,0);
    }

    for (int i = 0; i < M; i++)
    {
        ll L, R, C;
        cin >> L >> R >> C;
        L--;
        G[3 * sz + 2 * i].emplace_back(3 * sz + 2 * i + 1,C);
        for (L += sz, R += sz; L < R; L >>= 1, R >>= 1)
        {
            if (L & 1)
            {
                ll node = L++;
                if (node >= sz)
                {
                    G[node + sz].emplace_back(3 * sz + 2 * i,0);
                    G[3 * sz + 2 * i + 1].emplace_back(node + sz,0);
                }
                else
                {
                    G[node + sz].emplace_back(3 * sz + 2 * i,0);
                    G[3 * sz + 2 * i + 1].emplace_back(node,0);
                }
            }
            if (R & 1)
            {
                ll node = --R;
                if (node >= sz)
                {
                    G[node + sz].emplace_back(3 * sz + 2 * i,0);
                    G[3 * sz + 2 * i + 1].emplace_back(node + sz,0);
                }
                else
                {
                    G[node + sz].emplace_back(3 * sz + 2 * i,0);
                    G[3 * sz + 2 * i + 1].emplace_back(node,0);
                }
            }
        }
    }
    Dijkstra<ll> d(G);
    d.solve(2 * sz);
    cout << d.minc[2 * sz + N - 1] << endl;
    return 0;
}