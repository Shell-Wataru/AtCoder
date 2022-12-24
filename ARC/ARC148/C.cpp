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
#include <unordered_map>

using namespace std;
using ll = long long;

int dfs(vector<vector<ll>> &G, ll current,ll depth, vector<ll> &depths){
  depths[current] = depth;
  for(auto to:G[current]){
    dfs(G,to,depth+1,depths);
  }
  return 0;
}
int main()
{
  ll N,Q;
  cin >> N >> Q;
  vector<vector<ll>> G(N);
  vector<ll> P(N);
  vector<ll> depths(N);
  for(int i = 0;i < N-1;i++){
    ll p;
    cin >> p;
    p--;
    G[p].push_back(i+1);
    P[i+1] = p;
  }
  for(int i = 0;i < Q;i++){
    ll M;
    cin >> M;
    vector<pair<ll,ll>> vs(M);
    for(int j = 0;j < M;j++){
      ll v;
      cin >> v;
      v--;
      vs[j] = {depths[v],v};
    }
    sort(vs.rbegin(),vs.rend());
    ll ans = 0;
    unordered_map<ll,ll> children_count;
    for(int j = 0;j < M;j++){
      if (children_count[vs[j].second] == G[vs[j].second].size()){
        ans -= G[vs[j].second].size();
        ans++;
      }else{
        ans++;
        children_count[vs[j].second]++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
