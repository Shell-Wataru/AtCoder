#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

template <typename flow_t, typename cost_t>
struct PrimalDual
{
    const cost_t INF;

    struct edge
    {
        int to;
        flow_t cap;
        cost_t cost;
        int rev;
        bool isrev;
    };
    vector<vector<edge>> graph;
    vector<cost_t> potential, min_cost;
    vector<int> prevv, preve;

    PrimalDual(int V) : graph(V), INF(numeric_limits<cost_t>::max()) {}

    void add_edge(int from, int to, flow_t cap, cost_t cost)
    {
        graph[from].emplace_back((edge){to, cap, cost, (int)graph[to].size(), false});
        graph[to].emplace_back((edge){from, 0, -cost, (int)graph[from].size() - 1, true});
    }

    cost_t min_cost_flow(int s, int t, flow_t f)
    {
        int V = (int)graph.size();
        cost_t ret = 0;
        using Pi = pair<cost_t, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> que;
        potential.assign(V, 0);
        preve.assign(V, -1);
        prevv.assign(V, -1);

        while (f > 0)
        {
            min_cost.assign(V, INF);
            que.emplace(0, s);
            min_cost[s] = 0;
            while (!que.empty())
            {
                Pi p = que.top();
                que.pop();
                if (min_cost[p.second] < p.first)
                    continue;
                for (int i = 0; i < graph[p.second].size(); i++)
                {
                    edge &e = graph[p.second][i];
                    cost_t nextCost = min_cost[p.second] + e.cost + potential[p.second] - potential[e.to];
                    if (e.cap > 0 && min_cost[e.to] > nextCost)
                    {
                        min_cost[e.to] = nextCost;
                        prevv[e.to] = p.second, preve[e.to] = i;
                        que.emplace(min_cost[e.to], e.to);
                    }
                }
            }
            if (min_cost[t] == INF)
                return -1;
            for (int v = 0; v < V; v++)
                potential[v] += min_cost[v];
            flow_t addflow = f;
            for (int v = t; v != s; v = prevv[v])
            {
                addflow = min(addflow, graph[prevv[v]][preve[v]].cap);
            }
            f -= addflow;
            ret += addflow * potential[t];
            for (int v = t; v != s; v = prevv[v])
            {
                edge &e = graph[prevv[v]][preve[v]];
                e.cap -= addflow;
                graph[v][e.rev].cap += addflow;
            }
        }
        return ret;
    }

    void output()
    {
        for (int i = 0; i < graph.size(); i++)
        {
            for (auto &e : graph[i])
            {
                if (e.isrev)
                    continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << rev_e.cap + e.cap << ")" << endl;
            }
        }
    }
};

int solve()
{
    ll N;
    scanf("%lld", &N);
    PrimalDual<ll, ll> g(3 * N + 2);
    ll total = 0;
    for (ll i = 1; i <= N; i++)
    {
        ll k, l, r;
        scanf("%lld %lld %lld", &k, &l, &r);
        if (l < r)
        {
            total += r;
            g.add_edge(i, N + k, 1, r - l);
            if (k < N){
                g.add_edge(i, 2 * N + k +1, 1, 0);
            }
        }
        else
        {
            total += l;
            g.add_edge(i, N + k, 1, 0);
            if (k < N){
                g.add_edge(i, 2 * N + k + 1, 1, l - r);
            }
        }
    }
    for (size_t i = 1; i <= N; i++)
    {
        g.add_edge(0, i, 1, 0);
    }
    for (size_t i = 1; i <= N; i++)
    {
        g.add_edge(N + i, 3 * N + 1, 1, 0);
        if (i > 1)
        {
            g.add_edge(N + i, N + i - 1, i - 1, 0);
        }
    }

    for (size_t i = 1; i <= N; i++)
    {
        g.add_edge(2 * N + i, 3 * N + 1, 1, 0);
        if (i < N)
        {
            g.add_edge(2 * N + i, 2 * N + i + 1, N - i, 0);
        }
    }
    cout << total - g.min_cost_flow(0, 3 * N + 1, N) << "\n";
    return 0;
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}