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
#include <set>
using namespace std;
using ll = long long;

pair<ll,ll> dfs(vector<vector<pair<ll,ll>>> &G,ll current,ll parent){
  pair<ll,ll> ans = {0,current};
  for(auto e:G[current]){
    ll to = e.first;
    ll w= e.second;
    if (to != parent){
      auto p = dfs(G,to,current);
      if (p.first + w > ans.first){
        ans.first = p.first+w;
        ans.second = p.second;
      }
    }
  }
  return ans;
}

ll dfs2(vector<vector<pair<ll,ll>>> &G,ll current,ll parent,ll d,vector<ll> &distances){
  distances[current] = max(distances[current],d);
  for(auto e:G[current]){
    ll to = e.first;
    ll w= e.second;
    if (to != parent){
      dfs2(G,to,current,d+w,distances);
    }
  }
  return 0;
}
int main()
{
  ll N;
  cin >> N;
  vector<vector<pair<ll,ll>>> G(2*N);
  for(int i = 0;i < N-1;i++){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    G[a].push_back({b,c});
    G[b].push_back({a,c});
  }
  vector<ll> D(N);
  for(int i = 0;i < N;i++){
    cin >> D[i];
    G[i].push_back({i+N,D[i]});
  }
  auto p1 = dfs(G,0,-1);
  G[p1.second - N].pop_back();
  auto p2 = dfs(G,p1.second - N,-1);
  vector<ll> d1(2*N,0);
  vector<ll> d2(2*N,0);
  dfs2(G,p1.second-N,-1,0,d1);
  dfs2(G,p2.second-N,-1,0,d2);
  // cout << p1.second - N << endl;
  // cout << p2.second - N << endl;
  for(int i = 0;i < N;i++){
    ll ans = 0;
    if (i != p1.second-N){
      ans = max(ans,d1[i] + D[p1.second-N]);
    }
    if (i != p2.second-N){
      ans = max(ans,d2[i] + D[p2.second-N]);
    }
    cout << ans << endl;
  }
  return 0;
}
