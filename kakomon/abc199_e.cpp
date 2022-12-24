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

int main()
{
  ll N,M;
  cin >> N >> M;
  vector<vector<pair<ll,ll>>> conditions(N);
  for(int i = 0;i < M;i++){
    ll x,y,z;
    cin >> x >> y >> z;
    conditions[x].push_back({y,z});
  }
  // cout << "!!" << endl;
  vector<ll> DP(1ll<<N,0);
  DP[0] = 1;
  for(ll i = 0;i < (1ll<<N) - 1;i++){
    // cout << "i" << i << endl;
    ll x = __builtin_popcountll(i);
    for(auto c:conditions[x]){
      ll y = c.first;
      ll z = c.second;
      ll count = 0;
      for(ll j = 0;j < y;j++){
        if (i & 1ll<<j){
          count++;
        }
      }
      if (count > z){
        DP[i] = 0;
        break;
      }
    }
    if (DP[i] == 0){
      continue;
    }
    for(int j = 0;j < N;j++){
      if (!(i & 1ll<<j) ){
        DP[i | 1ll<<j] += DP[i];
      }
    }
  }
  cout << DP[(1ll<<N) - 1] << endl;
  return 0;
}
