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

using namespace std;
using ll = int;

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

int main()
{
    // 整数の入力
    ll H, W;
    cin >> H >> W;
    vector<string> G(H);
    for (int i = 0; i < H; i++)
    {
        cin >> G[i];
    }
    pair<ll, ll> start;
    pair<ll, ll> goal;
    Dinic<ll> dinic(2 * H * W);
    for (int i = 0; i < H; i++)
    {
        vector<ll> leaves;
        for (int j = 0; j < W; j++)
        {
            if (G[i][j] == 'S')
            {
                start = {i, j};
                leaves.push_back(j);
            }
            else if (G[i][j] == 'T')
            {
                goal = {i, j};
                leaves.push_back(j);
            }
            else if (G[i][j] == 'o')
            {
                leaves.push_back(j);
            }
        }
        for (int j = 0; j < leaves.size(); j++)
        {
            for (int k = 0; k < leaves.size(); k++)
            {
                dinic.add_edge(2 * (W * i + leaves[j]) + 1, 2 * (W * i + leaves[k]), 1);
                dinic.add_edge(2 * (W * i + leaves[k]) + 1, 2 * (W * i + leaves[j]), 1);
            }
        }
    }

    for (int i = 0; i < W; i++)
    {
        vector<ll> leaves;
        for (int j = 0; j < H; j++)
        {
            if (G[j][i] == 'S')
            {
                leaves.push_back(j);
            }
            else if (G[j][i] == 'T')
            {
                leaves.push_back(j);
            }
            else if (G[j][i] == 'o')
            {
                leaves.push_back(j);
            }
        }
        for (int j = 0; j < leaves.size(); j++)
        {
            for (int k = 0; k < leaves.size(); k++)
            {
                dinic.add_edge(2 * (W * leaves[j] + i) + 1, 2 * (W * leaves[k] + i), 1);
                dinic.add_edge(2 * (W * leaves[k] + i) + 1, 2 * (W * leaves[j] + i), 1);
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            dinic.add_edge(2 * (W * i + j), 2 * (W * i + j) + 1, 1);
        }
    }
    if (start.first == goal.first || start.second == goal.second){
        cout << -1 << endl;
    }else{
        cout << dinic.max_flow(2 * (W * start.first + start.second) + 1, 2 * (W * goal.first + goal.second)) << endl;
    }

    return 0;
}