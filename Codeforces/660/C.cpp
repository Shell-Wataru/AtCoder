#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

pair<ll,ll> dfs(vector<vector<ll>> &G, vector<ll> &P, vector<ll> &H, ll current, ll parent){
  ll child_goods = 0;
  ll child_bads = 0;
  ll can_make = true;
  for(auto to:G[current]){
    if (to != parent){
      auto p = dfs(G,P,H,to,current);
      if (p.first == -1){
        can_make = false;
        break;
      }
      child_goods += p.first;
      child_bads += p.second;
    }
  }
  ll total_peaple = P[current] + child_goods + child_bads;
  ll good = (total_peaple + H[current])/2;
  ll bad = (total_peaple - H[current])/2;
  if (can_make && good + bad == total_peaple && good - bad == H[current] && good >= child_goods && bad >= 0 && bad - P[current] <= child_bads){
    return {good,bad};
  }else{
    return {-1,-1};
  }
}
int solve()
{
    ll n,m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    vector<ll> P(n,0);
    vector<ll> H(n,0);
    vector<vector<ll>> G(n);
    for(int i = 0; i < n;i++){
      scanf("%lld",&P[i]);
    }
    for(int i = 0; i < n;i++){
      scanf("%lld",&H[i]);
    }
    for(int i = 0; i < n-1;i++){
      ll from,to;
      scanf("%lld",&from);
      scanf("%lld",&to);
      from--;
      to--;
      G[from].push_back(to);
      G[to].push_back(from);
    }
    auto p = dfs(G,P,H,0,-1);
    if (p.first == -1){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
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
    // cout << flush;
    return 0;
}
