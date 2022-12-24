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


ll solve(){
  ll N,M,K,L;
  cin >> N >> M  >> K >> L;
  vector<ll> A(N);
  vector<ll> B(L);
  vector<vector<pair<ll,ll>>> G(N);
  vector<pair<ll,ll>> distance_min(N,{numeric_limits<ll>::max(),-1});
  vector<ll> distance_all(N,numeric_limits<ll>::max());
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;

  for(int i = 0;i < L;i++){
    cin >> B[i];
    B[i]--;
    q.push({0,B[i],A[B[i]]});
  }
  for(int i = 0;i < M;i++){
    ll u,v,c;
    cin >> u >> v >> c;
    u--;v--;
    G[u].emplace_back(v,c);
    G[v].emplace_back(u,c);
  }
  while(!q.empty()){
    ll d = q.top()[0];
    ll c = q.top()[1];
    ll from = q.top()[2];
    q.pop();
    bool updated = false;
    if (d < distance_all[c] && from != distance_min[c].second && distance_min[c].second != -1){
      distance_all[c] = d;
      updated = true;
    }
    if (d < distance_min[c].first){
      distance_min[c] = {d,from};
      updated = true;
    }
    if (updated){
      for(auto e:G[c]){
        q.push({d+e.second,e.first,from});
      }
    }
  }

  // for(int i = 0;i < N;i++){
  //   cout << distance_min[i].first << " " << distance_min[i].second << "," << A[i] << endl;
  // }
  for(int i = 0;i < N;i++){
    if (i != 0){
      cout << " ";
    }
    ll d;
    if (distance_min[i].second != A[i]){
      d =  distance_min[i].first;
    }else{
      d = distance_all[i];
    }
    if (d == numeric_limits<ll>::max()){
      cout << -1;
    }else{
      cout << d;
    }
  }
  cout << "\n";
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 1; i <= N;i++){
    solve();
  // }
  cout << flush;
  return 0;
}
