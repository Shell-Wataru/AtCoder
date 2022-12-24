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

int fix(vector<vector<ll>> &A,
        vector<vector<ll>> &B,
        vector<vector<bool>> &visited, ll i, ll j)
{
    // cout << i << "," << j << endl;
    ll N = A.size();
    ll M = A[0].size();
    ll ans = 0;
    visited[i][j] = true;
    vector<pair<ll, ll>> whites;
    vector<pair<ll, ll>> blacks;
    queue<pair<ll, ll>> q;
    q.push({i, j});
    vector<pair<ll, ll>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};
    while (!q.empty())
    {
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();
        if (A[x][y] == 0)
        {
            whites.push_back({x, y});
        }
        else
        {
            blacks.push_back({x, y});
        }
        for (auto d : directions)
        {
            ll next_x = x + d.first;
            ll next_y = y + d.second;
            if (0 <= next_x && next_x < N &&
                0 <= next_y && next_y < M &&
                !visited[next_x][next_y] &&
                A[next_x][next_y] != B[next_x][next_y] &&
                A[x][y] != A[next_x][next_y])
            {
                q.push({next_x, next_y});
                visited[next_x][next_y] = true;
            }
        }
    }
    Dinic<ll> dinic(whites.size() + blacks.size() + 2);
    map<pair<ll, ll>, ll> black_indices;
    for (int i = 0; i < blacks.size(); i++)
    {
        black_indices[blacks[i]] = i;
        dinic.add_edge(whites.size() + 1 + i, whites.size() + blacks.size() + 1, 1);
    }
    for (int i = 0; i < whites.size(); i++)
    {
        ll x = whites[i].first;
        ll y = whites[i].second;
        dinic.add_edge(0, i + 1, 1);
        for (auto d : directions)
        {
            ll next_x = x + d.first;
            ll next_y = y + d.second;
            if (0 <= next_x && next_x < N &&
                0 <= next_y && next_y < M &&
                A[next_x][next_y] != B[next_x][next_y] &&
                A[x][y] != A[next_x][next_y])
            {
                dinic.add_edge(i + 1, whites.size() + 1 + black_indices[{next_x, next_y}], 1);
            }
        }
    }
    // cout << "m_flow:" << dinic.max_flow(0,whites.size() + blacks.size() + 1) << endl;
    return  whites.size() + blacks.size() - dinic.max_flow(0,whites.size() + blacks.size() + 1);
}

int solve()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    vector<vector<ll>> B(N, vector<ll>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (size_t i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> B[i][j];
        }
    }
    ll ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j] && A[i][j] != B[i][j])
            {
                ans += fix(A, B, visited, i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // while(T--){
    solve();
    // }
    return 0;
}
