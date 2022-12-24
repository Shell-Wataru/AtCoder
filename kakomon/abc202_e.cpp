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
#include <stack>

using namespace std;
using ll = long long;

int dfs1(vector<vector<ll>> &G,ll current,ll parent,vector<ll> &depths, ll depth){
  depths[current] = depth;
  for(auto to:G[current]){
    if (to != parent){
      dfs1(G,to,current,depths,depth+1);
    }
  }
  return 0;
}

vector<ll> dfs2(vector<vector<ll>> &G,ll current,ll parent,vector<ll> &depths ,vector<vector<ll>> &sorted_queries, map<pair<ll,ll>,ll> &answers){
  vector<ll> counts = {};
  for(auto to:G[current]){
    if (to != parent){
      auto child_counts = dfs2(G,to,current,depths,sorted_queries,answers);
      if (child_counts.size() > counts.size()){
        swap(counts,child_counts);
      }
      for(int i = 0;i < child_counts.size();i++){
        counts[counts.size()-1-i] += child_counts[child_counts.size()-1-i];
      }
    }
  }
  counts.push_back(1);
  // cout << current << endl;
  // for(auto c:counts){
  //   cout << c << ",";
  // }
  // cout << endl;
  for(auto d:sorted_queries[current]){
    ll real_d = d - depths[current];
    if (real_d < 0 || real_d >= counts.size()){
      answers[{current,d}] = 0;
    }else{
      answers[{current,d}] = counts[counts.size() - 1 - real_d];
    }
  }
  return counts;
}
int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<vector<ll>> G(N);
  vector<ll> depths(N);
  for(int i = 1;i < N;i++){
    ll p;
    cin >> p;
    p--;
    G[p].push_back(i);
  }
  dfs1(G,0,-1,depths,0);
  // for(int i = 0;i < N;i++){
  //   cout << depths[i] << ",";
  // }
  // cout << endl;
  ll Q;
  cin >> Q;
  vector<pair<ll,ll>> queries(Q);
  map<pair<ll,ll>,ll> answers;
  vector<vector<ll>>  sorted_queries(N);
  for(int i = 0;i < Q;i++){
    ll u,d;
    cin >> u >> d;
    u--;
    queries[i] = {u,d};
    sorted_queries[u].push_back(d);
  }
  dfs2(G,0,-1,depths,sorted_queries,answers);
  for(int i = 0;i < Q;i++){
    cout << answers[queries[i]] << endl;
  }
  return 0;
}
