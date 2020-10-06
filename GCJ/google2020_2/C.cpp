#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;

template <typename flow_t>
struct Dinic
{
    const flow_t INF;

    struct edge
    {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };

    vector<vector<edge>> graph;
    vector<int> min_cost, iter;

    Dinic(int V) : INF(numeric_limits<flow_t>::max()), graph(V) {}

    void add_edge(int from, int to, flow_t cap, int idx = -1)
    {
        graph[from].emplace_back((edge){to, cap, (int)graph[to].size(), false, idx});
        graph[to].emplace_back((edge){from, 0, (int)graph[from].size() - 1, true, idx});
    }

    bool bfs(int s, int t)
    {
        min_cost.assign(graph.size(), -1);
        queue<int> que;
        min_cost[s] = 0;
        que.push(s);
        while (!que.empty() && min_cost[t] == -1)
        {
            int p = que.front();
            que.pop();
            for (auto &e : graph[p])
            {
                if (e.cap > 0 && min_cost[e.to] == -1)
                {
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
            }
        }
        return min_cost[t] != -1;
    }

    flow_t dfs(int idx, const int t, flow_t flow)
    {
        if (idx == t)
            return flow;
        for (int &i = iter[idx]; i < graph[idx].size(); i++)
        {
            edge &e = graph[idx][i];
            if (e.cap > 0 && min_cost[idx] < min_cost[e.to])
            {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t)
    {
        flow_t flow = 0;
        while (bfs(s, t))
        {
            iter.assign(graph.size(), 0);
            flow_t f = 0;
            while ((f = dfs(s, t, INF)) > 0)
                flow += f;
        }
        return flow;
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
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
};

string solve()
{
    ll N;
    cin >> N;
    vector<pair<ll, ll>> G;
    for (int i = 0; i < N; i++)
    {
        ll x, y;
        cin >> x >> y;
        G.push_back({x, y});
    }
    Dinic<ll> dinic_vertical(2 * N + 2);
    Dinic<ll> dinic_horizontal(2 * N + 2);
    for (int i = 0; i < N; i++)
    {
        dinic_vertical.add_edge(0, i + 1, 1);
        dinic_horizontal.add_edge(0, i + 1, 1);
        dinic_vertical.add_edge(N + i + 1, 2 * N + 1, 1);
        dinic_horizontal.add_edge(N + i + 1, 2 * N + 1, 1);
    }
    for (int i = 0; i < N; i++)
    {
        auto p1 = G[i];
        for (int j = i + 1; j < N; j++)
        {
            auto p2 = G[j];
            if (p1.first == p2.first)
            {
                dinic_vertical.add_edge(i + 1, N + j + 1, 1);
            }
            if (p1.second == p2.second)
            {
                dinic_horizontal.add_edge(i + 1, N + j + 1, 1);
            }
        }
    }
    ll max_frow_horizontal = dinic_horizontal.max_flow(0,2*N+1);
    ll max_frow_vertical = dinic_vertical.max_flow(0,2*N+1);
    ll horizontal_count = min(2 * max_frow_horizontal + 2,N);
    ll vertical_count = min(2 * max_frow_vertical + 2,N);
     return to_string(max(vertical_count,horizontal_count));
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}