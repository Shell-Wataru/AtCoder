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

ll dfs(ll current,ll parent,vector<vector<ll>> &G, vector<pair<ll,ll>> &answers, ll weight){
  // cout << current << ":" << weight << endl;
  answers[current].first = weight;
  bool first_child = true;
  for(auto to:G[current]){
    if (to != parent){
      if (!first_child){
        weight++;
      }
      first_child = false;
      weight = dfs(to,current,G,answers,weight);
    }
  }
  answers[current].second = weight;
  return weight;
}

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> G(N);
  for(int i = 0;i < N-1;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<pair<ll,ll>> ans(N);
  dfs(0,-1,G,ans,0);
  for(int i = 0;i < N;i++){
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
  }
  cout << flush;
  return 0;
}
