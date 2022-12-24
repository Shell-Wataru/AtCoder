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

pair<int, int> dfs(vector<vector<ll>> &G, int u, int par)
{ // 最遠点間距離と最遠点を求める
  pair<int, int> ret = make_pair(0, u);
  for (auto to : G[u])
  {
    if (to == par)
      continue;
    auto next = dfs(G, to, u);
    next.first += 1;
    ret = max(ret, next);
  }
  return ret;
}

struct Doubling
{
  const int LOG;
  vector< vector< int > > table;

  Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t))
  {
    table.assign(LOG, vector< int >(sz, -1));
  }

  void set_next(int k, int x)
  {
    table[0][k] = x;
  }

  void build()
  {
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int k, int64_t t)
  {
    for(int i = LOG - 1; i >= 0; i--) {
      if((t >> i) & 1) k = table[i][k];
      if (k == -1){
        return -1;
      }
    }
    return k;
  }
};

ll make_doubling(vector<vector<ll>> &G,ll current,ll parent, Doubling &d){
  for(auto to:G[current]){
    if (to != parent){
      d.set_next(to,current);
      // cout << to << " " << current << endl;
      make_doubling(G,to,current,d);
    }
  }
  return 0;
}

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> G(N);
  for (int i = 0; i < N - 1; i++)
  {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  auto p1 = dfs(G,0,-1);
  auto p2 = dfs(G,p1.second,-1);
  // cout  << "p1 "<< p1.second + 1<< endl;
  // cout  << "p2 "<< p2.second + 1<< endl;
  Doubling d1(N,2*N);

  Doubling d2(N,2*N);
  make_doubling(G,p1.second,-1,d1);
  // cout << "!" << endl;
  make_doubling(G,p2.second,-1,d2);
  d1.build();
  d2.build();
  // for(int i = 0;i < N;i++){
  //   cout << i << "->" <<  d2.table[0][i] << endl;
  // }
  ll Q;
  cin >> Q;
  for(int i = 0;i < Q;i++){
    ll u,k;
    cin >> u >> k;
    u--;
    ll a = d1.query(u,k);
    // cout <<"a:" << a << endl;
    ll b = d2.query(u,k);
    // for(int j = 0;j <= k+1;j++){
    //   cout << d1.query(u,j) << ",";
    // }
    // cout << endl;
    // for(int j = 0;j <= k+1;j++){
    //   cout << d2.query(u,j) << ",";
    // }
    // cout << endl;

    // cout <<"b:" << b << endl;
    if (a != -1){
      cout << a + 1 << "\n";
    }else if (b != -1){
      cout << b + 1 << "\n";
    }else{
      cout << -1 << "\n";
    }
  }
  cout << flush;
  return 0;
}
