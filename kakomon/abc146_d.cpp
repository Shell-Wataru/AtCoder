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

ll dfs(vector<vector<ll>> &G, ll current, ll parent, ll to_parent_color,map<pair<ll,ll>,ll> &colors){
    ll color = 1;
    ll max_color = G[current].size();
    for(auto to:G[current]){
        if (color == to_parent_color){
            color++;
        }
        if (to != parent){
            colors[{current,to}] = color;
            max_color = max(max_color,dfs(G,to,current,color,colors));
            color++;
        }
    }
    return max_color;
}
int main()
{
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    vector<pair<ll,ll>> E;
    map<pair<ll,ll>,ll> colors;
    for (size_t i = 0; i < N-1; i++)
    {
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        E.push_back({u,v});
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll max_color = dfs(G,0,-1,0,colors);
    cout << max_color << "\n";
    for(int i = 0; i < N-1;i++){
        cout << colors[E[i]] << "\n";
    }
    cout << flush;
    return 0;
}