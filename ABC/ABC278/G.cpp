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
#include <atcoder/mincostflow>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

ll apply(set<pair<ll,ll>> &ranges,ll a,ll b){
  auto iter = ranges.lower_bound({a,numeric_limits<ll>::max()});
  iter--;
  pair<ll,ll> range = *iter;
  ranges.erase(iter);
  pair<ll,ll> left = {range.first ,a};
  pair<ll,ll> right = {a+b ,range.second};
  if (left.second - left.first > 0){
    ranges.insert(left);
  }
  if (right.second - right.first > 0){
    ranges.insert(right);
  }
  return 0;
}

ll g(vector<ll> &grundy,set<pair<ll,ll>> &ranges){
  ll ret = 0;
  for(auto r:ranges){
    ret ^= grundy[r.second - r.first];
  }
  return ret;
}

int main()
{
  ll N,L,R;
  cin >> N >> L >> R;
  vector<ll> grundy(N+1);
  for(int i = 0;i < L;i++){
    grundy[i] = 0;
  }
  for(ll i = L;i <= N;i++){
    vector<bool> founds(N,false);
    for(int j = L;i-j >= 0 && j <= R ;j++){
      founds[grundy[i-j]] = true;
    }
    for(int k = 1;k <= N/2;k++){
      for(int j = L;i-j-k >= 0 && k <= i-j-k && j <= R;j++){
        founds[grundy[k] ^  grundy[i-j-k]] = true;
      }
    }
    for(int j = 0;j <= N;j++){
      if (!founds[j]){
        grundy[i] = j;
        // cout << i << ":" << j << endl;
        break;
      }
    }
  }
  set<pair<ll,ll>> ranges;
  ranges.insert({0,N});
  if (grundy[N] == 0){
    cout << "Second" << endl;
    ll a, b;
    cin >> a >> b;
    if (a == 0 && b == 0){
      return 0;
    }
    a--;
    apply(ranges,a,b);
  }else{
    cout << "First" << endl;
  }
  while(true){
    ll current_g = g(grundy,ranges);
    pair<ll,ll> my_move = {-1,-1};
    for(auto r:ranges){
      ll i = r.second-r.first;
      ll target_g = current_g ^ grundy[i];
      for(int j = L;i-j >= 0 && j <= R;j++){
        if (grundy[i-j] == target_g){
          my_move = {r.first,j};
          break;
        }
      }
      for(int k = 1;k <= N/2;k++){
        for(int j = L;i-j-k >= 0 && k <= i-j-k && j <= R;j++){
          if ((grundy[k] ^  grundy[i-j-k]) == target_g){
            my_move = {r.first+k,j};
            break;
          }
        }
      }
    }

    cout << my_move.first + 1 << " " << my_move.second << endl;
    apply(ranges,my_move.first,my_move.second);
    pair<ll,ll> opponent_move= {-1,-1};
    cin >>  opponent_move.first >> opponent_move.second;
    if (opponent_move.first == 0 && opponent_move.second == 0){
      return 0;
    }
    opponent_move.first--;
    apply(ranges,opponent_move.first,opponent_move.second);
  }
  return 0;
}
