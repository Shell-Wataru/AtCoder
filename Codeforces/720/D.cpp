#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <list>
using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<set<ll>> G(n);
    vector<pair<ll,ll>> edges(n-1);
    priority_queue<vector<ll>> q;
    queue<ll> one_degree_nodes;
    for(int i = 0;i < n-1;i++){
      ll u,v;
      scanf("%lld",&u);
      scanf("%lld",&v);
      u--;
      v--;
      edges.push_back({u,v});
      G[u].insert(v);
      G[v].insert(u);
    }
    for(auto &e:edges){
      if (G[e.first].size() >= 3 && G[e.second].size() >= 3){
        q.push({2,e.first,e.second});
      }else if(G[e.first].size() >= 3 || G[e.second].size() >= 3){
        q.push({1,e.first,e.second});
      }
    }
    for(int i = 0;i < n;i++){
      if (G[i].size() == 1){
        one_degree_nodes.push(i);
      }
    }
    vector<vector<ll>> ans;
    while(!q.empty()){
      auto d = q.top();
      q.pop();
      if (d[0] == 2){
        if (G[d[1]].size() >= 3 && G[d[2]].size() >= 3){
          ll x = one_degree_nodes.front();
          one_degree_nodes.pop();
          ll y = one_degree_nodes.front();
          one_degree_nodes.pop();
          ans.push_back({d[1],d[2],x,y});;
          G[d[1]].erase(d[2]);
          G[d[2]].erase(d[1]);
        }else if (G[d[1]].size() >= 3 || G[d[2]].size() >= 3){
          q.push({1,d[1],d[2]});
        }
      }else if (d[0] == 1){
        if (G[d[1]].size() >= 3 || G[d[2]].size() >= 3){
          q.push({1,d[1],d[2]});
        }
      }
    }
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
