#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

ll dfs(vector<vector<pair<ll,ll>>> &G,ll current,ll parent,ll target){
    if (current == target){
        return 0;
    }
    ll ans = 1;
    for(auto e:G[current]){
        ll to = e.first;
        ll w = e.second;
        if (to != parent){
            ans = max(ans,gcd(w,dfs(G,to,current,target)));
        }
    }
    return ans;
}

int main()
{
    ll n = 6;
    vector<vector<pair<ll,ll>>> G(n);
    vector<vector<ll>> edges = {
        {1, 2, 10},
        {2, 3, 4},
        {2, 4, 6},
        {1, 5, 2},
        {5, 6, 10}
    };
    for(auto e:edges){
        ll u = e[0];
        ll v = e[1];
        ll w = e[2];
        u--;v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    vector<vector<ll>> ans(n,vector<ll>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            ans[i][j] = dfs(G,i,-1,j);
        }
    }
    // for(int i = 0;i < n;i++){
    //     for(int j = i+1;j < n;j++){
    //         cout << i << "->" << j << ":" << ans[i][j] << endl;
    //     }
    // }
    cout << G.size() << endl;
    for(auto e:edges){
        cout << e[0] << " " << e[1] << endl;
    }
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            ll a,b;
            cin >> a >> b;
            cerr << a <<  "," << b << endl;
            break;
        }else{
            ll t;
            cin >> t;
            vector<ll>  targets(t);
            for(int i = 0;i < t;i++){
                cin >> targets[i];
                targets[i]--;
            }
            ll a = 0;
            for(int i = 0;i < t;i++){
                for(int j = i+1;j < t;j++){
                    a = max(a,ans[targets[i]][targets[j]]);
                }
            }
            cout << a << endl;
        }
    }
    return 0;
}
