#define _USE_MATH_DEFINES
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
namespace mp = boost::multiprecision;

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

int dfs(StronglyConnectedComponents<UnWeightedGraph> &scc,vector<ll> &DP,ll current,ll add,vector<bool> &visited){
  if (visited[current]){
    return 0;
  }
  visited[current] = true;
  DP[current] += add;
  for(auto to: scc.edges[current]){
      dfs(scc,DP,to,add,visited);
    }
  return 0;
}
int main()
{
  ll N,M;
  cin >> N >> M;
  UnWeightedGraph g(N);
  for(int i =0;i < M;i++){
    ll a,b;
    cin >> a>> b;
    a--;
    b--;
    g[a].push_back(b);
  }
  StronglyConnectedComponents<UnWeightedGraph> scc(g);
  vector<ll> DP(scc.nodes.size(),0);
  ll ans = 0;
  for(int i = 0;i < scc.edges.size();i++){
    ans += scc.nodes[i].size() * scc.nodes[i].size();
    ans += scc.nodes[i].size() * DP[i];
    vector<bool> visited(scc.nodes.size(),false);
    for(auto to: scc.edges[i]){
      dfs(scc,DP,to,scc.nodes[i].size(),visited);
    }
  }
  cout << ans << endl;
  return 0;
}