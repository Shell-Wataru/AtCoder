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

int solve()
{
  ll N, M;
  cin >> N >> M;
  vector<pair<ll,ll>> chocolates(N);
  vector<pair<ll,ll>> boxes(M);
  priority_queue<pair<ll,ll>> q;
  map<ll,ll> can_uses;
  for(int i =0;i < N;i++){
    scanf("%lld",&chocolates[i].first);
     ;
  }
  for(int i =0;i < N;i++){
    scanf("%lld",&chocolates[i].second);
  }
  for(int i =0;i < M;i++){
    scanf("%lld",&boxes[i].first);
  }
  for(int i =0;i < M;i++){
    scanf("%lld",&boxes[i].second);
  }
  sort(chocolates.rbegin(),chocolates.rend());
  for(int i = 0;i < M;i++){
    q.push(boxes[i]);
  }
  for(int i = 0;i < N;i++){
    while(!q.empty() && q.top().first >= chocolates[i].first){
      can_uses[q.top().second]++;
      q.pop();
    }
    auto iter = can_uses.lower_bound(chocolates[i].second);
    if (iter != can_uses.end()){
      can_uses[iter->first]--;
      if (can_uses[iter->first] == 0){
        can_uses.erase(iter->first);
      }
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

int main()
{
  // ll N;
  // cin >> N;
  // for(int i = 0;i < N;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
