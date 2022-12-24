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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

int main()
{
  ll H,W;
  cin >> H >> W;
  vector<vector<ll>> A(H,vector<ll>(W));
  vector<vector<ll>> tA(W,vector<ll>(H));
  for(int i = 0;i < H;i++){
    for(int j = 0;j < W;j++){
      cin >> A[i][j];
    }
  }
  vector<pair<ll,ll>> ranges;
  for(int i = 0;i < H;i++){
    ll min_v = numeric_limits<ll>::max();
    ll max_v = numeric_limits<ll>::min();
    for(int j = 0;j < W;j++){
      min_v = min(min_v,A[i][j]);
      max_v = max(max_v,A[i][j]);
    }
    ranges.emplace_back(min_v,max_v);
  }
  sort(ranges.begin(),ranges.end());
  ll max_value = -1;
  for(int i = 0;i < H;i++){
    if (ranges[i].first < max_value ){
      cout << "No" << endl;
      return 0;
    }
    max_value = max(max_value,ranges[i].second);
  }

  vector<pair<ll,ll>> t_ranges;
  for(int i = 0;i < W;i++){
    ll min_v = numeric_limits<ll>::max();
    ll max_v = numeric_limits<ll>::min();
    for(int j = 0;j < H;j++){
      min_v = min(min_v,A[j][i]);
      max_v = max(max_v,A[j][i]);
    }
    t_ranges.emplace_back(min_v,max_v);
  }
  sort(t_ranges.begin(),t_ranges.end());
  ll t_max_value = -1;
  for(int i = 0;i < W;i++){
    if (t_ranges[i].first < t_max_value ){
      cout << "No" << endl;
      return 0;
    }
    t_max_value = max(t_max_value,ranges[i].second);
  }
  cout << "Yes" << endl;
  return 0;
}
