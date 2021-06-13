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
#include <set>
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
        nodes.resize(ptr);
        for (int i = 0; i < g.size(); i++)
        {
            for (auto &to : g[i])
            {
                int x = comp[i], y = comp[to];
                if (x == y)
                    continue;
                edges[x].push_back(y);
            }
        }
        for (int i = 0; i < g.size(); i++)
        {
            nodes[comp[i]].push_back(i);
        }
    }
};

int dfs(StronglyConnectedComponents<UnWeightedGraph> &scc,ll current,ll &answer,vector<ll> &DP){
    answer += scc.nodes[current].size() * (scc.nodes[current].size() + 1 )/2;
}

int main()
{
    UnWeightedGraph g(3);
    g[0].push_back(1);
    g[1].push_back(0);
    g[1].push_back(2);
    StronglyConnectedComponents<UnWeightedGraph> scc(g);
    for (auto components : scc.nodes)
    {
        for (auto c : components)
        {
            cout << c;
        }
        cout << endl;
    }
    vector<ll> DP(scc.nodes.size());
    for (int i = 0; i < scc.edges.size(); i++)
    {
        for (auto to : scc.edges[i])
        {
            cout << i << "->" << to << endl;
        }
    }
}