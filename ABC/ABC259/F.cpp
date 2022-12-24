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
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

const long long BASE_NUM = 1000000007;
map<pair<ll,ll>,ll> cache;

ll dfs(vector<vector<pair<ll,ll>>> &G,vector<ll> &D,ll current,ll parent){
  if (cache.count({current,D[current]}) == 1){
    return cache[{current,D[current]}];
  }
  vector<pair<ll,ll>> compare;
  for(auto e:G[current]){
    ll to = e.first;
    if (to != parent){
      ll used = numeric_limits<ll>::min()/4;
      ll not_used = dfs(G,D,to,current);
      if (D[to] >= 1){
        D[to]--;
        used = e.second + dfs(G,D,to,current);
        D[to]++;
      }
      compare.push_back({used-not_used,not_used});
    }
  }
  sort(compare.rbegin(),compare.rend());
  ll ans_all = 0;
  for(int i = 0;i < compare.size();i++){
    if (i < D[current] && compare[i].first >= 0){
      ans_all += compare[i].first + compare[i].second;
    }else{
      ans_all += compare[i].second;
    }
  }
  cache[{current,D[current]}] = ans_all;
  return ans_all;
}

int solve()
{
  ll N;
  cin >> N;
  vector<ll> D(N);
  for(int i = 0;i < N;i++){
    cin >> D[i];
  }
  vector<vector<pair<ll,ll>>> G(N);
  for(int i = 0;i < N-1;i++){
    ll u,v,w;
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].push_back({v,w});
    G[v].push_back({u,w});
  }
  ll root;
  for(int i =0 ;i< N;i++){
    if (G[i].size() == 1){
      root = i;
      break;
    }
  }

  cout << dfs(G,D,root,-1) << endl;
  // for(int i = 0;i < N;i++){
  //   cout << i + 1 << ":" << cache[{i,D[i]}] << endl;
  // }
  return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
