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

priority_queue<ll> dfs(vector<vector<ll>> &G,vector<ll> &A, ll current, ll parent){
  priority_queue<ll> q;
  q.push(A[current]);
  bool has_child = false;
    for(auto to:G[current]){
      if (to != parent){
        has_child = true;
        auto child_q =  dfs(G,A,to,current);
        if (child_q.size() > q.size()){
          swap(q,child_q);
        }
        while(!child_q.empty()){
          q.push(child_q.top());
          child_q.pop();
        }
      }
    }
    if (has_child){
      q.pop();
    }
    return q;
}

ll solve(){
  ll N;
  cin >> N;
  vector<ll> A(N,0);
  vector<vector<ll>> G(N);
  for(int i = 1;i < N;i++){
    cin >> A[i];
  }
  for(int i = 0;i < N-1;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  cout << "!" << endl;
  auto q =  dfs(G,A,0,-1);
  cout << q.size() << endl;
  cout << q.top() << endl;
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
