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

using namespace std;
using ll = long long;

ll next_current(string &ans,ll &current){
  while(ans[current] != '#' && current < ans.size()){
    current++;
  }
  return 0;
}
int main()
{
  ll N;
  cin >> N;
  vector<ll> P(2*N);
  vector<ll> Q(2*N);
  for(int i = 0;i < 2*N;i++){
    cin >> P[i];
    P[i]--;
  }
  for(int i = 0;i < 2*N;i++){
    cin >> Q[i];
    Q[i]--;
  }
  string ans(2*N,'#');
  queue<ll> p_must_uses;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
  priority_queue<pair<ll,ll>> qq;
  for(int i = 0;i < 2*N;i++){
    pq.push({P[i],i});
  }
  ll current = 0;
  while(!pq.empty() && current < 2*N){
    auto p = pq.top();
    pq.pop();
    if (p.second == current){
      ans[current] = '(';
      next_current(ans,current);
      auto next_p = pq.top();
      pq.pop();
      if (next_p.second == current){
        ans[current] = ')';
        next_current(ans,current);
      }else{
        cout << -1 << endl;
        return 0;
      }
    }else{
      ll to = p.second;
      ans[to] = '(';
      auto next_p = pq.top();
      pq.pop();
      if (next_p.second == current){
        ans[current] = ')';
        next_current(ans,current);
      }else{
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
