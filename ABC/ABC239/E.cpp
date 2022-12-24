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

vector<ll> dfs(ll current,ll parent,vector<vector<ll>> &G,vector<ll> &X, map<pair<ll,ll>,ll> &answers){
  priority_queue<ll> q;
  for(auto to:G[current]){
    if (to != parent){
      auto biggests = dfs(to,current,G,X,answers);
      for(auto b:biggests){
        q.push(b);
      }
    }
  }
  q.push(X[current]);
  vector<ll> answer;
  while(!q.empty() && answer.size() <= 20){
    answer.push_back(q.top());
    q.pop();
  }
  for(int i = 0;i < answer.size();i++){
    answers[{current,i}] = answer[i];
  }
  return answer;
}

int main()
{
  ll N,Q;
  cin >> N >> Q;
  vector<ll> X(N);
  vector<vector<ll>> G(N);
  for(int i = 0;i < N;i++){
    cin >> X[i];
  }
  for(int i = 0;i < N-1;i++){
    ll u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  map<pair<ll,ll>,ll> answers;
  vector<pair<ll,ll>> queries;
  for(int i = 0;i < Q;i++){
    ll v,k;
    cin >> v >> k;
    v--;
    k--;
    answers[{v,k}] = -1;
    queries.push_back({v,k});
  }
  dfs(0,-1,G,X,answers);
  for(int i = 0;i < Q;i++){
    cout << answers[queries[i]] << "\n";
  }
  cout << flush;
  return 0;
}
