#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

pair<ll,ll> dfs(vector<vector<ll>> &G,ll current){
  // cout << current << endl;
  if (G[current].empty()){
    return {1,1};
  }else if (G[current].size() == 1){
    ll max_depth = 0;
    ll patterns = 0;
    for(auto to:G[current]){
      auto p = dfs(G,to);
      patterns += p.first;
      max_depth = max(max_depth,p.second+1);
    }
    return {max(max_depth,patterns),max_depth};
  }else{
    ll max_depth = 0;
    ll patterns = 0;
    for(auto to:G[current]){
      auto p = dfs(G,to);
      patterns += p.first;
      max_depth = max(max_depth,p.second+1);
    }
    return {max(max_depth,patterns),max_depth};
  }
}
int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<vector<ll>> G(n);
  for(int i = 1;i < n;i++){
    ll p;
    scanf("%lld",&p);
    p--;
    G[p].push_back(i);
  }
  // cout << "!" << endl;
  cout << dfs(G,0).first << endl;;

  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  // cout << flush;
  return 0;
}
