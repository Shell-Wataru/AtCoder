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
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


ll dfs(vector<set<ll>> &G,ll current,ll parent,pair<ll,ll> &edge,vector<ll> &a, ll target){
  ll current_total = a[current];
  for(auto to:G[current]){
    if (to != parent){
      ll children_total = dfs(G,to,current,edge,a,target);
      if (edge.first != -1){
        return 0;
      }else if (children_total == target){
        edge = {current,to};
        return 0;
      }else{
        current_total ^= children_total;
      }
    }
  }
  return current_total;
}
int solve()
{
  ll n,k;
  scanf("%lld",&n);
  scanf("%lld",&k);
  vector<set<ll>> G(n);
  vector<ll> a(n);
  for(int i = 0;i< n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i< n-1;i++){
    ll u,v;
    scanf("%lld",&u);
    scanf("%lld",&v);
    u--;v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  ll total_xor = 0;
  for(int i = 0;i < n;i++){
    total_xor ^= a[i];
  }
  // cout << total_xor << endl;
  if (total_xor == 0){
    cout << "Yes\n";
  }else{
    if (k == 2){
      cout << "No\n";
      return 0;
    }
    pair<ll,ll> edge = {-1,-1};
    dfs(G,0,-1,edge,a,total_xor);
    if (edge.first == -1){
      cout << "No\n";
      return 0;
    }
    G[edge.first].erase(edge.second);
    G[edge.second].erase(edge.first);
    edge = {-1,-1};
    dfs(G,0,-1,edge,a,total_xor);
    if (edge.first == -1){
      cout << "No\n";
      return 0;
    }
    cout << "Yes\n";
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
