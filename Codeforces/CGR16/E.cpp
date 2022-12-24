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

ll dfs(vector<set<ll>> &G,ll current,ll parent,map<ll,ll> &leaves_count){
  vector<ll> edges(G[current].begin(),G[current].end());
  for(auto to:edges){
    if (to != parent){
      dfs(G,to,current,leaves_count);
    }
  }
  if(G[current].size() > 1 && parent != -1){
    // cout << current << endl;
    leaves_count[G[current].size()-1]++;
    G[parent].erase(current);
  }
  return 0;
}
int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<set<ll>> G(n);
  for(int i = 0;i < n-1;i++){
    ll a,b;
    cin >> a >> b;
    a--;b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  map<ll,ll> leaves_count;
  dfs(G,0,-1,leaves_count);
  ll ans = 0;
  for(auto c:leaves_count){
    // cout << c.first << "," << c.second << endl;
    ans += (c.first-1)*c.second;
  }
  if (G[0].size() == 0){
    ans++;
  }else{
    ans += G[0].size();
  }
  cout << ans << "\n";
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
