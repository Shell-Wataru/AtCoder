#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll p;
    scanf("%lld", &p);
    ll N = 1ll<<p;
    vector<vector<ll>> G(N);
    vector<pair<ll,ll>> edges(N -1);
    vector<ll> node_weights(N);
    unordered_map<pair<ll,ll>,ll> edge_weights;
    for (int i = 0; i < N-1; i++)
    {
        ll u, v;
        scanf("%lld", &u);
        scanf("%lld", &v);
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
        edges[i] = {u,v};
    }
    queue<vector<ll>> q;
    q.push({0,-1,0});
    node_weights[0] = N;
    ll x = 1;
    while(!q.empty()){
        ll current = q.front()[0];
        ll parent = q.front()[1];
        ll depth = q.front()[2];
        q.pop();
        for(auto to:G[current]){
            if (to != parent){
                if (depth % 2 == 0){
                    edge_weights[{min(to,current),max(to,current)}] = N^x;
                    node_weights[to] = x;
                    x++;
                    q.push({to,current,depth+1});
                }else{
                    edge_weights[{min(to,current),max(to,current)}] = x;
                    node_weights[to] = N^x;
                    x++;
                    q.push({to,current,depth+1});
                }
            }
        }
    }
    cout << 1 << "\n";
    for(int i =0; i< N;i++){
        if (i != 0){
            cout << " ";
        }
        cout << node_weights[i];
    }
    cout << "\n";
    for(int i =0; i< N-1;i++){
        if (i != 0){
            cout << " ";
        }
        cout << edge_weights[{min(edges[i].first,edges[i].second),max(edges[i].first,edges[i].second)}];
    }
    cout << "\n";
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
