#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;


int solve()
{
  ll n,m;
  scanf("%lld%lld",&n,&m);
  vector<vector<ll>> G(n);
  for(int i = 0;i < m;i++){
    ll a,b;
    scanf("%lld%lld",&a,&b);
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  map<ll,vector<ll>> desired_topic_map;
  vector<ll> desired_topics(n);
  map<ll,ll> order;
  for(int i = 0;i < n;i++){
    ll t;
    scanf("%lld",&t);
    desired_topic_map[t].push_back(i);
    desired_topics[i] = t;
  }
  ll index = 1;
  bool can_make = true;
  for(int i = 1;i <= n;i++){
    for(auto j:desired_topic_map[i]){
      set<ll> lowers;
      bool same_neighbor = false;
      for(auto to:G[j]){
        if (desired_topics[to] < i){
          lowers.insert(desired_topics[to]);
        }else if(desired_topics[to] == i){
          same_neighbor = true;
        }
      }
      // cout << j << " " << lowers.size() << endl;
      if (!same_neighbor && lowers.size() == i - 1){
        order[index] = j;
        index++;
      }else{
        // cout << j << endl;
        can_make = false;
        break;
      }
    }
  }

  if (can_make){
    for(int i = 1;i <= n;i++){
      if (i != 1){
        cout << " ";
      }
      cout << order[i] + 1;
    }
    cout << endl;
  }else{
    cout << -1 << endl;
  }
  return 0;
}

int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
    solve();
  // }
  return 0;
}