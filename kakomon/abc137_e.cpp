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

ll BASE_NUM = 1000000007;

struct Edge
{
    ll from, to;
    ll w;
};

bool bellman_ford(int n, vector<Edge> &edges, vector<ll> &dists)
{
    for (int i = 0; i < n; i++)
    {
        // cout << "i" << i << endl;
        for (auto e : edges)
        {
            if (dists[e.from] + e.w < dists[e.to] )
            {
                dists[e.to] = dists[e.from] + e.w;
                if (i == n - 1)
                {
                    return true; // n回目にも更新があるなら負の閉路が存在
                }
            }
        }
    }
    return false;
}

int find_visitables(vector<bool> &visitables,vector<vector<ll>> &G,ll current){
    visitables[current] = true;
    for(auto to:G[current]){
        if (!visitables[to]){
            find_visitables(visitables,G,to);
        }
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll N,M,P;
    cin >> N >> M >> P;
    vector<Edge> edges(M);
    vector<Edge> usable_edges;
    vector<vector<ll>> revG(N);
    vector<vector<ll>> G(N);
    vector<bool> visitable_to_goal(N,false);
    vector<bool> visitable_from_start(N,false);
    for(int i = 0;i < M;i++){
        ll u,v,c;
        cin >> u >> v >> c;
        u--;
        v--;
        edges[i].from = u;
        edges[i].to = v;
        edges[i].w = - c + P;
        revG[v].push_back(u);
        G[u].push_back(v);
    }
    find_visitables(visitable_to_goal,revG,N-1);
    find_visitables(visitable_from_start,G,0);
    for(int i = 0;i < M;i++){
        if (visitable_to_goal[edges[i].from] && visitable_to_goal[edges[i].to] &&
            visitable_from_start[edges[i].from] && visitable_from_start[edges[i].to]){
            // cout << edges[i].from + 1 << "->" << edges[i].to + 1 << endl;
            usable_edges.push_back(edges[i]);
        }
    }
    vector<ll> dists(N, numeric_limits<ll>::max()/2);
    dists[0] = 0;
    if (bellman_ford(N,usable_edges,dists)){
        cout << -1 << endl;
    }else{
        cout << max(- dists[N-1],0ll) << endl;
    }
    return 0;
}