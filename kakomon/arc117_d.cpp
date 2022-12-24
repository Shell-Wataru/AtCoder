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
#include <stack>

using namespace std;
using ll = long long;


ll find_farthest_point(vector<vector<ll>> &G, int current, int parent, int distance, int &farthest_point, ll &farthest_distance)
{
    // cout << current << endl;
    if (distance > farthest_distance)
    {
        farthest_distance = distance;
        farthest_point = current;
    }
    for (auto to : G[current])
    {
        if (to == parent)
        {
            continue;
        }
        find_farthest_point(G, to, current, distance + 1, farthest_point, farthest_distance);
    }
    return 0;
}

ll set_depth(vector<vector<ll>> &G,ll current,ll parent,vector<ll> &depths, ll d){
    ll max_d = d;
    for(auto to:G[current]){
        if (to != parent){
            max_d = max(max_d,set_depth(G,to,current,depths,d+1));
        }
    }
    depths[current] = max_d;
    return max_d;
}

ll dfs(vector<vector<ll>> &G,ll current,ll parent,vector<ll> &e,vector<ll> &depths, ll value){
    e[current] = value;
    vector<pair<ll,ll>> edges;
    for(auto to:G[current]){
        if (to != parent){
            edges.push_back({depths[to],to});
        }
    }
    sort(edges.begin(),edges.end());
    for(auto edge:edges){
        ll to = edge.second;
        if (to != parent){
            value = max(value,dfs(G,to,current,e,depths,value+1));
        }
    }
    return value+1;
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for(int i = 0;i < N-1;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    ll d = -1;
    int a;
    find_farthest_point(G,0,-1,0,a,d);
    vector<ll> depth(N);
    vector<ll> e(N,-1);
    // cout << a << endl;
    set_depth(G,a,-1,depth,0);
    dfs(G,a,-1,e,depth,1);
    // for(int i = 0;i < N;i++){
    //     if (i != 0){
    //         cout << " ";
    //     }
    //     cout << depth[i];
    // }
    // cout << endl;
    for(int i = 0;i < N;i++){
        if (i != 0){
            cout << " ";
        }
        cout << e[i];
    }
    cout << endl;
    return 0;
}
