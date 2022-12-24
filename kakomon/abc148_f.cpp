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

pair<ll,ll> dfs(vector<vector<ll>> &G,int parent,ll current,ll v,ll d_u){
    ll d_v = numeric_limits<ll>::max()/2;
    ll farthest = d_u;
    ll farthest_to_v = 0;
    if (current == v){
        d_v = 0;
    }

    for(auto to:G[current]){
        if (to != parent){
            auto p = dfs(G,current,to,v,d_u+1);
            if (p.second != numeric_limits<ll>::max()/2){
                farthest_to_v = p.first;
                d_v = p.second + 1;
            }
            farthest = max(farthest,p.first);
        }
    }

    // cout << current << ":" << farthest << endl;
    // cout << current << ":" << farthest_to_v << endl;
    if (d_v < d_u || d_v == numeric_limits<ll>::max()/2){
        return {farthest,d_v};
    }else{
        return {farthest_to_v,d_v};
    }
}
int main()
{
    ll N,u,v;
    cin >> N >> u >> v;
    u--;
    v--;
    vector<vector<ll>> G(N);
    for (size_t i = 0; i < N-1; i++)
    {
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto p = dfs(G,-1,v,u,0);
    cout << p.first - 1 << endl;
    return 0;
}