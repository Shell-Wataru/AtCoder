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

ll dfs(vector<vector<ll>> &G, vector<ll> &depths, vector<ll> &nexts, ll current){
  if (depths[current] != -1){
    return depths[current];
  }
  ll ans = 0;
  for(auto to:G[current]){
    ll d = dfs(G,depths,nexts,to) + 1;
    if (d > ans){
      ans = d;
      nexts[current] = to;
    }

  }
  depths[current] = ans;
  return ans;
}
int solve()
{
  ll n,M;
  scanf("%lld", &n);
  scanf("%lld", &M);
  vector<vector<ll>> G(n);
  vector<vector<ll>> ranges;
  for(int i = 0;i < M;i++){
    ll m,l,r;
    scanf("%lld",&m);
    scanf("%lld",&l);
    scanf("%lld",&r);
    l--;
    m--;
    ranges.push_back({l,1,m});
    ranges.push_back({r,-1,m});
  }
  sort(ranges.begin(),ranges.end());
  map<ll,ll> count;
  for(int i = 0;i < ranges.size();i++){
    if (ranges[i][1] == -1){
      count[ranges[i][2]]--;
      if (count[ranges[i][2]] == 0){
        count.erase(ranges[i][2]);
      }
    }else{
      count[ranges[i][2]]++;
      auto before_itr = count.find(ranges[i][2]);
      if (before_itr != count.begin()){
        before_itr--;
        G[before_itr->first].push_back(ranges[i][2]);
      }
      auto next_itr = count.find(ranges[i][2]);
      next_itr++;
      if (next_itr != count.end()){
        G[ranges[i][2]].push_back(next_itr->first);
      }
    }
  }
  // for(int i = 0;i < n;i++){
  //   cout << i << "->";
  //   for(auto to:G[i]){
  //     cout << to << ",";
  //   }
  //   cout << endl;
  // }
  ll ans = -1;
  ll ans_start_index = -1;
  vector<ll> depths(n,-1);
  vector<ll> nexts(n,-1);
  for(int i = 0;i < n;i++){
    ll d = dfs(G,depths,nexts,i);
    // cout << i << ":" << d << endl;
    if (d > ans){
      ans = d;
      ans_start_index = i;
    }
  }
  vector<bool> used(n,false);
  used[ans_start_index] = true;
  while(nexts[ans_start_index] != -1){
    used[nexts[ans_start_index]] = true;
    ans_start_index = nexts[ans_start_index];
  }
  cout << n - ans - 1 << "\n";
  vector<ll> unused;
  for(int i = 0;i < n;i++){
    if (!used[i]){
      unused.push_back(i+1);
    }
  }
  if (unused.size() > 0){
    for(int i = 0;i < unused.size();i++){
      if (i != 0){
        cout << " ";
      }
      cout << unused[i];
    }
    cout << "\n";
  }
  cout << flush;
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
