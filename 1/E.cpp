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
ll BASE_NUM = 1000000007;

int main()
{
  // 整数の入力
  ll N,M,Q;
  cin >> N >> M >> Q;
  vector<vector<ll>> G(N);
  vector<ll> colors(N);
  for(int i =0;i < M;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for(int i = 0;i < N;i++){
    cin >> colors[i];
  }
  for(int i = 0;i < Q;i++){
    ll type;
    cin >> type;
    if (type == 1){
      ll x;
      cin >> x;
      x--;
      cout << colors[x] << endl;
      for(auto &to:G[x]){
        colors[to] = colors[x];
      }
    }else{
      ll x,y;
      cin >> x >> y;
      x--;
      cout << colors[x] << endl;
      colors[x] = y;
    }
  }
  return 0;
}
