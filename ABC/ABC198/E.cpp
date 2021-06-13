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

void dfs(vector<vector<ll>> &G, vector<ll> &C,ll current ,ll parent,vector<ll> &good_points,vector<bool> &used_colors){
  bool already_used = used_colors[C[current]];
  if (!already_used){
    good_points.push_back(current);
    used_colors[C[current]] = true;
  }
  for(auto to:G[current]){
    if (to != parent){
      dfs(G,C,to,current,good_points,used_colors);
    }
  }
  if (!already_used){
    used_colors[C[current]] = false;
  }
}
int main()
{
  ll N;
  cin >> N;
  vector<ll> C(N);
  vector<bool> used_colors(100000,false);
  for(int i = 0;i < N;i++){
    cin >> C[i];
    C[i]--;
  }
  vector<vector<ll>> G(N);
  for (size_t i = 0; i < N-1; i++)
  {
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<ll> good_nodes;
  dfs(G,C,0,-1,good_nodes,used_colors);
  sort(good_nodes.begin(),good_nodes.end());
  for(auto g:good_nodes){
    cout << g + 1<< endl;
  }
  return 0;
}
