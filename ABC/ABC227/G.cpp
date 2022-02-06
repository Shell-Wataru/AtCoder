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

int main()
{
  ll N,M,Q;
  cin >> N >> M >> Q;
  vector<set<ll>> G(N);
  vector<ll> parent(N,-1);
  vector<ll> queries(Q);
  for(int i = 0;i < M;i++){
    ll u,v;
    u--;v--;
    G[u].insert(v);
    G[v].insert(u);
  }
  for(int i = 0;i < Q;i++){
    cin >> queries[i];
    queries[i]--;
  }
  reverse(queries.begin(),queries.end());
  for(int i = 0;i < Q;i++){
    ll x= queries[i];
    for(auto to:G[x]){
      parent[to] = x;

    }
  }
  return 0;
}
