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

void dfs(vector<vector<ll>> &G,vector<bool> &visited,deque<ll> &path, ll current){
    visited[current] = true;
    for(auto to:G[current]){
        if (!visited[to]){
            path.push_back(to);
            dfs(G,visited,path,to);
            return;
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
    }
    vector<bool> visited(N,false);
    deque<ll> path;
    path.emplace_back(0);
    dfs(G,visited,path, 0);
    reverse(path.begin(),path.end());
    dfs(G,visited,path, 0);
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