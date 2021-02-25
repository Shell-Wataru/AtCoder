#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

const int NONE = -1;
const pair<ll, ll> MAX_VALUE = {numeric_limits<ll>::max(), numeric_limits<ll>::max()};

struct S
{
    long long node, prev;
    pair<ll, ll> cost;
    S(long long n, pair<ll, ll> c, long long p) : node(n), cost(c), prev(p) {}
    bool operator>(const S &s) const
    {
        return cost.first + cost.second * cost.second > s.cost.first + s.cost.second * s.cost.second;
    }
};

class Dijkstra
{
    long long n;
    vector<vector<pair<ll, ll>>> G;

public:
    vector<pair<ll, ll>> minc;
    vector<long long> prev;

    Dijkstra(vector<vector<pair<ll, ll>>> &G) : n(G.size()), G(G), minc(n, MAX_VALUE), prev(G.size()) {}

    void solve(long long start)
    {
        minc.assign(n, MAX_VALUE);
        priority_queue<S, vector<S>, greater<S>> pq;
        pq.push(S(start, {0, 0}, NONE));
        while (!pq.empty())
        {
            S s = pq.top();
            pq.pop();
            if (s.cost.second == 0 && minc[s.node] < s.cost)
            {
                continue;
            }
            minc[s.node] = s.cost;
            prev[s.node] = s.prev;
            for (auto itr = G[s.node].begin(); itr != G[s.node].end(); ++itr)
            {
                if (s.cost.second == 0)
                {
                    pq.push(S(itr->first, {s.cost.first, itr->second}, s.node));
                }
                else
                {
                    ll w_sum = s.cost.second + itr->second;
                    if (minc[itr->first].first <= s.cost.first + w_sum * w_sum)
                    {
                        continue;
                    }
                    pq.push(S(itr->first, {s.cost.first + w_sum * w_sum, 0}, s.node));
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            // cout << i << ":" << minc[i] << endl;
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
    ll n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<vector<pair<ll, ll>>> G(2 * n);
    for (size_t i = 0; i < m; i++)
    {
        ll u;
        ll v;
        ll w;
        scanf("%lld", &u);
        scanf("%lld", &v);
        scanf("%lld", &w);
        u--;
        v--;
        G[2 * u].emplace_back(2 * v + 1, w);
        G[2 * u + 1].emplace_back(2 * v, w);
        G[2 * v].emplace_back(2 * u + 1, w);
        G[2 * v + 1].emplace_back(2 * u, w);
    }
    Dijkstra D(G);
    D.solve(0);
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        if (D.minc[2 * i].first == numeric_limits<ll>::max())
        {
            cout << -1;
        }
        else
        {
            cout << D.minc[2 * i].first;
        }
    }
    cout << endl;
    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
