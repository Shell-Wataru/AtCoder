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

int dfs(vector<vector<ll>> &G,vector<ll> &depths,ll current,ll parent, ll depth){
    // cout << current << ":" << depth << endl;
    depths[current] = depth;
    for(auto to:G[current]){
        if (to != parent){
            dfs(G,depths,to,current,depth+1);
        }
    }
    return 0;
}

int dfs2(vector<vector<ll>> &G,vector<ll> &points,ll current,ll parent){
    if (parent != -1){
        points[current] += points[parent];
    }

    for(auto to:G[current]){
        if (to != parent){
            dfs2(G,points,to,current);
        }
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    vector<pair<ll,ll>> edges(N-1);
    vector<ll> depths(N);
    vector<ll> points(N,0);
    for(int i = 0;i < N-1;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
        edges[i] = {u,v};
    }
    dfs(G,depths,0,-1,0);

    ll Q;
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        ll t,e,x;
        cin >> t >> e >> x;
        e--;
        ll a = edges[e].first;
        ll b = edges[e].second;
        if (t == 1){
            if (depths[a] < depths[b]){
                points[0]+= x;
                points[b]-= x;
            }else{
                points[a] += x;
            }
        }else{
            if (depths[a] < depths[b]){
                points[b] += x;
            }else{
                points[0]+= x;
                points[a]-= x;
            }
        }
    }
    dfs2(G,points,0,-1);
    for(int i =0 ;i < N;i++){
        cout << points[i]  << "\n";
    }
    cout << flush;
    return 0;
}