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


int main()
{
  // 整数の入力
  ll M;
  cin >> M;
  vector<vector<ll>> G(9);
  for(int i = 0;i < M;i++){
    ll u,v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector<ll> initial(9,8);
  for(int i = 0;i < 8;i++){
    ll p;
    cin >> p;
    p--;
    initial[p] = i;
  }
  queue<pair<ll,vector<ll>>> q;
  q.push({0,initial});
  map<vector<ll>,ll> ans;
  ans[initial] = 0;
  while(!q.empty()){
    // cout << ans.size() << endl;
    ll d = q.front().first;
    vector<ll> current = q.front().second;

    q.pop();
    ll blank = -1;
    for(int i = 0;i < 9;i++){
      if (current[i] == 8){
        blank = i;
        break;
      }
    }
    // cout << "B:" << blank << endl;
    for(auto to:G[blank]){
      // cout << to << ",";
      // cout << current[to] << "~" << current[8] << ",";
      swap(current[to],current[blank]);
      if (ans.find(current) == ans.end()){
        ans[current] = d+1;
        q.push({d+1,current});
      }
      swap(current[to],current[blank]);
    }
    // cout << endl;
  }
  vector<ll> goal(9);
  iota(goal.begin(),goal.end(),0);
  // cout << ans.size() << endl;
  // for(int i = 0;i < 9;i++){
  //     cout << goal[i] << ",";
  //   }
  //   cout << endl;
  if (ans.find(goal) == ans.end()){
    cout << -1 << endl;
  }else{
    cout << ans[goal] << endl;
  }
  return 0;
}
