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

using namespace std;
using ll = long long;

ll dfs(vector<vector<pair<ll,ll>>> &G, ll current ,ll parent, ll d,vector<ll> &colors){
    if (d % 2 == 0){
        colors[current] = 0;
    }else{
        colors[current] = 1;
    }
    for(auto &p: G[current]){
        if (p.first != parent){
            dfs(G,p.first,current,d+p.second,colors);
        }
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<pair<ll,ll>>> G(N);
    for(int i = 0;i < N-1;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    vector<ll> colors(N);
    dfs(G,0,-1,0,colors);
    for(int i = 0;i < N;i++){
        cout << colors[i] << endl;
    }
    return 0;
}