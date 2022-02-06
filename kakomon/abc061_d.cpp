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
    ll N,M;
    cin >> N >> M;
    vector<Edge> edges(M);
    vector<vector<ll>> G(N);
    vector<vector<ll>> revG(N);
    vector<bool> visitable_from_start(N,false);
    vector<bool> visitable_to_goal(N,false);
    for(int i = 0;i < M;i++){
        cin >> edges[i].from >> edges[i].to >> edges[i].w;
        edges[i].from--;
        edges[i].to--;
        edges[i].w *= -1;
        G[edges[i].from].push_back(edges[i].to);
        revG[edges[i].to].push_back(edges[i].from);
    }
    find_visitables(visitable_from_start,G,0);
    find_visitables(visitable_to_goal,revG,N-1);
    vector<Edge> removed_edges;
    for(auto e:edges){
        if (visitable_from_start[e.to] && visitable_from_start[e.from] && visitable_to_goal[e.to] && visitable_to_goal[e.from]){
            removed_edges.push_back(e);
        }
    }
    vector<ll> dists(N, numeric_limits<ll>::max()/2);
    dists[0] = 0;
    if (bellman_ford(N, removed_edges, dists)){
        cout << "inf" << endl;
    }else{
        cout << -dists[N-1] << endl;
    }
    return 0;
}