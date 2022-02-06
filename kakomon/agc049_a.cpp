#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

template <typename G>
struct StronglyConnectedComponents
{
    const G &g;
    UnWeightedGraph gg, rg;
    vector<int> comp, order, used;
    vector<vector<ll>> nodes;
    vector<vector<ll>> edges;
    vector<vector<ll>> rev_edges;

    StronglyConnectedComponents(G &g) : g(g), gg(g.size()), rg(g.size()), comp(g.size(), -1), used(g.size())
    {
        for (int i = 0; i < g.size(); i++)
        {
            for (auto e : g[i])
            {
                gg[i].emplace_back((int)e);
                rg[(int)e].emplace_back(i);
            }
        }
        build();
    }

    int operator[](int k)
    {
        return comp[k];
    }

    void dfs(int idx)
    {
        if (used[idx])
            return;
        used[idx] = true;
        for (int to : gg[idx])
            dfs(to);
        order.push_back(idx);
    }

    void rdfs(int idx, int cnt)
    {
        if (comp[idx] != -1)
            return;
        comp[idx] = cnt;
        for (int to : rg[idx])
            rdfs(to, cnt);
    }

    void build()
    {
        for (int i = 0; i < gg.size(); i++)
            dfs(i);
        reverse(begin(order), end(order));
        int ptr = 0;
        for (int i : order)
            if (comp[i] == -1)
                rdfs(i, ptr), ptr++;

        edges.resize(ptr);
        rev_edges.resize(ptr);
        nodes.resize(ptr);
        for (int i = 0; i < g.size(); i++)
        {
            for (auto &to : g[i])
            {
                int x = comp[i], y = comp[to];
                if (x == y)
                    continue;
                edges[x].push_back(y);
                rev_edges[y].push_back(x);
            }
        }
        for (int i = 0; i < g.size(); i++)
        {
            nodes[comp[i]].push_back(i);
        }
    }
};

int solve()
{
    int n;
    scanf("%d", &n);
    UnWeightedGraph g(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '1')
            {
                g[i].push_back(j);
            }
        }
    }
    StronglyConnectedComponents<UnWeightedGraph> scc(g);
    //   vector<ll> parent_sizes(scc.nodes.size());
    double ans = 0;
    for (int i = 0; i < scc.nodes.size(); i++)
    {
        vector<bool> visited(scc.nodes.size(), false);
        ll parent_size = 0;
        queue<ll> q;
        q.push(i);
        while (!q.empty())
        {
            ll current = q.front();
            q.pop();
            for (auto to : scc.rev_edges[current])
            {
                if (!visited[to])
                {
                    parent_size += scc.nodes[to].size();
                    visited[to] = true;
                    q.push(to);
                }
            }
        }
        //   parent_sizes[i] = parent_size;
        ans += 1.0 * scc.nodes[i].size() / (scc.nodes[i].size() + parent_size);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
