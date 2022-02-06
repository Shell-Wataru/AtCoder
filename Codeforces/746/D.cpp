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

int dfs(vector<set<ll>> &G,vector<ll> &nodes,set<ll> &candidates, ll current,ll parent){
  nodes.push_back(current);
  for(auto to:G[current]){
    if (to != parent && candidates.find(to) != candidates.end()){
      dfs(G,nodes,candidates,current,parent);
    }
  }
  return 0;
}

ll store_centroid(vector<set<ll>> &g, vector<ll> &centroid, ll current, ll parent)
{
  ll n = g.size();
  ll descendants = 1;
  bool iscentroid = true;
  for (auto to : g[current])
  {
    if (to != parent)
    {
      ll to_descendants = store_centroid(g, centroid, to, current);
      if (to_descendants > n / 2)
        iscentroid = false;
      descendants += to_descendants;
    }
  }
  if (n - descendants > n / 2)
  {
    iscentroid = false;
  }
  if (iscentroid)
    centroid.push_back(current);
  return descendants;
}

int query(vector<ll> &nodes){
  cout << nodes.size();
  for(auto n:nodes){
    cout << " " << n;
  }
  cout << endl;
  ll ans;
  cin >> ans;
  return ans;
}
int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<set<ll>> G(n);
  for (int i = 0; i < n; i++)
  {
    ll u, v;
    scanf("%lld", &u);
    scanf("%lld", &v);
    u--;
    v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  vector<ll> nodes(n);
  iota(nodes.begin(),nodes.end(),0);
  set<ll> candidates(nodes.begin(),nodes.end());
  ll maximum = query(nodes);
  while(true){
    vector<ll> centroids;
    store_centroid(G,centroids,0,-1);
    nodes.clear();
    if (centroids.size() == 2){
      dfs(G,nodes,candidates,centroids[0],centroids[1]);
      if (maximum == query(nodes)){
        candidates = set<ll>(nodes.begin(),nodes.end());
      }else{
        nodes.clear();
        dfs(G,nodes,candidates,centroids[1],centroids[0]);
        nodes.push_back(centroids[0]);
        candidates = set<ll>(nodes.begin(),nodes.end());
      }
    }else{

    }


  }
  return 0;
}

int main()
{
  // // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  // cout << flush;
  return 0;
}
