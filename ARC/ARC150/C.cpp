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

using namespace std;
using ll = long long;

int main()
{
  ll N,M,K;
  cin >> N >> M >> K;
  vector<vector<ll>> G(N);
  for(int i = 0;i < M;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<ll> A(N);
  vector<ll> B(K);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    A[i]--;
  }
  for(int i = 0;i < K;i++){
    cin >> B[i];
    B[i]--;
  }

  deque<ll> q;
  q.push_back(0);
  vector<ll> min_indices(N,numeric_limits<ll>::max()/2);
  vector<bool> visited1(N,false);
  if (A[0] == B[0]){
    min_indices[0] = 1;
  }else{
    min_indices[0] = 0;
  }
  while(!q.empty()){
    auto current = q.front();
    q.pop_front();
    if (!visited1[current]){
      visited1[current] = true;

      for(auto to:G[current]){
        if (min_indices[current] < K && A[to] == B[min_indices[current]]){
          min_indices[to] = min(min_indices[to],min_indices[current]+1);
          q.push_back(to);
        }else{
          min_indices[to] = min(min_indices[to],min_indices[current]);
          q.push_front(to);
        }

      }
    }
  }


  // cout << min_indices[N-1] << endl;
  if (min_indices[N-1] < K){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  return 0;
}
