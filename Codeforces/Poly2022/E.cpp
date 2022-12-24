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

pair<bool,ll> dfs(ll current,ll parent, ll d, ll depth,vector<vector<ll>> &G,vector<bool> &a_must_visits,vector<bool> &b_must_visits){
    ll max_depth = numeric_limits<ll>::min()/2;
    bool visit_here = false;
    if (a_must_visits[current]){
        max_depth = depth;
        visit_here = true;
    }

    for(auto to:G[current]){
        if (to != parent){
            auto p = dfs(to,current,d,depth+1,G,a_must_visits,b_must_visits);
            if (p.first){
                visit_here = true;
                max_depth = max(max_depth, p.second);
            }

        }
    }
    // cout << current  << ":"  << depth << "-" << max_depth << endl;
    if (visit_here && max_depth - depth >= d){
        b_must_visits[current] = true;
    }
    return {visit_here,max_depth};
}

bool dfs2(ll current,ll parent,vector<vector<ll>> &G,vector<bool> &a_must_visits,ll &ans){
    bool visit_here = false;
    if (a_must_visits[current]){
        visit_here = true;
    }

    for(auto to:G[current]){
        if (to != parent){
            auto p = dfs2(to,current,G,a_must_visits,ans);
            if (p){
                // cout << "to:" << to << endl;
                visit_here = true;
                ans+= 2;
            }

        }
    }
    return visit_here;
}

int solve()
{
  ll n,d;
  cin >> n >> d;
  vector<vector<ll>> G(n);
  for(int i = 0;i < n-1;i++){
    ll u,v;
    scanf("%lld",&u);
    scanf("%lld",&v);

    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  ll m1,m2;
  cin >> m1;
  vector<bool> a_must_visits(n);
  for(int i = 0;i < m1;i++){
    ll u;
    scanf("%lld",&u);
    u--;
    a_must_visits[u] = true;
  }
  cin >> m2;
  vector<bool> b_must_visits(n);
  for(int i = 0;i < m2;i++){
    ll u;
    scanf("%lld",&u);
    u--;
    b_must_visits[u] = true;
  }
  ll ans = 0;
  dfs(0,-1,d,0,G,a_must_visits,b_must_visits);
  dfs(0,-1,d,0,G,b_must_visits,a_must_visits);
  dfs2(0,-1,G,a_must_visits,ans);
  dfs2(0,-1,G,b_must_visits,ans);
//   for(int i = 0;i < n;i++){
//     cout << a_must_visits[i] << ",";
//   }
//   cout << endl;
//     for(int i = 0;i < n;i++){
//     cout << b_must_visits[i] << ",";
//   }
//   cout << endl;
  cout << ans << "\n";
  return 0;
}

int main()
{

  // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
  cout << flush;
  return 0;
}
