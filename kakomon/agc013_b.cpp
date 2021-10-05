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

void dfs(vector<vector<ll>> &G,set<pair<ll,ll>> &edges,vector<bool> &visited,deque<ll> &path, ll current){
    visited[current] = true;
    ll n = G[current].size();
    for(auto to:G[current]){
        if (!visited[to]){
            if (edges.find({path.front(),to}) != edges.end()){
                path.emplace_front(to);
            }else if (edges.find({path.back(),to}) != edges.end()){
                path.emplace_back(to);
            }
            dfs(G,edges,visited,path,to);
        }
    }
    return;
}
int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    set<pair<ll,ll>> edges;
    for (size_t i = 0; i < M; i++)
    {
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edges.emplace(a,b);
        edges.emplace(b,a);
    }
    vector<bool> visited(N,false);

    deque<ll> path;
    path.emplace_back(0);
    dfs(G,edges,visited,path, 0);
    cout << path.size() << "\n";
    for(int i = 0;i < path.size();i++){
        if (i != 0){
            cout << " ";
        }
        cout << path[i] + 1;
    }
    cout <<  "\n";
    cout << flush;
   return 0;
}