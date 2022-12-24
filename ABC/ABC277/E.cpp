#define _USE_MATH_DEFINES
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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,M,K;
  cin >> N >> M >> K;
  vector<vector<pair<ll,ll>>> G(2*N);
  for(int i = 0;i < M;i++){
    ll u,v,a;
    cin >> u >> v >> a;
    u--;v--;
    G[2*u+a].push_back({2*v+a,1});
    G[2*v+a].push_back({2*u+a,1});
  }
  for(int i = 0;i < K;i++){
    ll s;
    cin >> s;
    s--;
    G[2*s].push_back({2*s+1,0});
    G[2*s+1].push_back({2*s,0});
  }
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  vector<ll> mind(2*N,numeric_limits<ll>::max());
  q.push({0,1});
  while(!q.empty()){
    ll current = q.top().second;
    ll d = q.top().first;
    // cout << current <<endl;
    q.pop();
    if (d < mind[current]){
      mind[current] = d;
      for(auto e:G[current]){
        q.push({d+e.second,e.first});
      }
    }
  }
  ll ans =min(mind[2*(N-1)],mind[2*(N-1)+1]);
  if (ans == numeric_limits<ll>::max()){
    cout << -1 << endl;
  }else{
    cout << min(mind[2*(N-1)],mind[2*(N-1)+1]) << endl;
  }

  return 0;
}