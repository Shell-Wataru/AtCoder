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
  ll N,M;
  cin >> N >> M;
  vector<ll> H(N);
  vector<vector<ll>> G(N);
  for(int i = 0;i < N;i++){
    cin >> H[i];
  }
  for(int i = 0;i < M;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<ll> distances(N,numeric_limits<ll>::max());
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  q.push({0,0});
  while(!q.empty()){
    auto p = q.top();
    q.pop();
    ll current = p.second;
    ll d = p.first;
    if (d < distances[current]){
      distances[current] = d;
      for(auto to:G[current]){
        q.push({d+abs(H[current] - H[to]),to});
      }
    }
  }
  ll ans = numeric_limits<ll>::min();
  for(int i = 0;i < N;i++){
    ll x = (distances[i] + H[i] - H[0])/2;
    ll y = (distances[i] - H[i] + H[0])/2;
    ans = max(ans,y - 2*x);
  }
  cout << ans << endl;
  return 0;
}
