#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<vector<pair<ll,ll>>> Edges(n,vector<pair<ll,ll>>(n,{numeric_limits<ll>::max(),numeric_limits<ll>::max()}));
  priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
  vector<vector<ll>> G(n);
  for (ll i = 0; i < m; i++)
  {
    ll u,v,c;
    scanf("%lld",&u);
    scanf("%lld",&v);
    scanf("%lld",&c);
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
    q.push({u,v,c,c});
  }
  while(!q.empty()){
    auto data = q.top();
    q.pop();
    ll u = data[0];
    ll v = data[1];
    ll total_c = data[2];
    ll c = data[3];

    if (total_c  < Edges[u][v].first || c < Edges[u][v].second){
for(auto to:G[v]){
        q.push({v,to,total_c+c,c});
      }
      for(auto to:G[u]){
        q.push({u,to,total_c+c,c});
      }
    }
      if(make_pair(total_c,c) < Edges[u][v]){
      Edges[u][v] = {total_c,c};
      Edges[v][u] = {total_c,c};
      // for(auto to:G[v]){
      //   q.push({v,to,total_c+c,c});
      // }
      // for(auto to:G[u]){
      //   q.push({u,to,total_c+c,c});
      // }
    }
  }
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q2;
  q2.push({0,0});
  vector<ll> min_d(n,numeric_limits<ll>::max());
  while(!q2.empty()){
    auto p = q2.top();
    q2.pop();
    ll current = p.second;
    ll d= p.first;
    if (d <  min_d[current]){
      min_d[current] = d;
      for(int i = 0;i < n;i++){
        if (Edges[current][i].first != numeric_limits<ll>::max()){
          q2.push({d+Edges[current][i].first,i});
        }

      }
    }
  }
  cout << min_d[n-1] << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
