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

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> a(N,vector<ll>(N));
  for(int i = 0;i < N;i++){
    for(int j = 0;j < N;j++){
      cin >> a[i][j];
    }
  }
  vector<vector<unordered_map<ll,ll>>> DP1(N,vector<unordered_map<ll,ll>>(N));
  vector<vector<unordered_map<ll,ll>>> DP2(N,vector<unordered_map<ll,ll>>(N));
  DP1[0][0][a[0][0]] = 1;
  DP2[N-1][N-1][a[N-1][N-1]] = 1;
  for(int i = 0;i < N;i++){
    for(int j = 0;i+j < N;j++){
      if (i+1 < N){
        for(auto p:DP1[i][j]){
          DP1[i+1][j][p.first ^ a[i+1][j]] += p.second;
        }
      }
      if (j+1 < N){
        for(auto p:DP1[i][j]){
          DP1[i][j+1][p.first ^ a[i][j+1]] += p.second;
        }
      }
    }
  }

  for(int i = N-1;i >= 0;i--){
    for(int j = N-1;i+j >= N;j--){
      if (i-1 >= 0){
        for(auto p:DP2[i][j]){
          DP2[i-1][j][p.first ^ a[i-1][j]] += p.second;
        }
      }
      if (j-1 < N){
        for(auto p:DP2[i][j]){
          DP2[i][j-1][p.first ^ a[i][j-1]] += p.second;
        }
      }
    }
  }
  ll ans = 0;
  for(int i = 0;i < N;i++){
    ll j = N-1-i;
    // cout << i << "," << j << endl;
    if (i+1 < N){
      for(auto p:DP1[i][j])
        ans += DP2[i+1][j][p.first] *p.second;
    }
    if (j+1 < N){
      for(auto p:DP1[i][j])
        ans += DP2[i][j+1][p.first] *p.second;
    }
  }
  cout << ans << endl;
  return 0;
}
