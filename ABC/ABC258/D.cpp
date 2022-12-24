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


int solve()
{
  ll N,X;
  cin >> N >> X;
  vector<pair<ll,ll>> AB(N);
  for(int i = 0;i < N;i++){
    cin >> AB[i].first >> AB[i].second;
  }
  ll ans = numeric_limits<ll>::max();
  ll current_clears = 0;
  ll currrent_time = 0;
  for(int i = 0;i < N;i++){
    current_clears++;
    currrent_time+= AB[i].first + AB[i].second;
    ans =min(ans, currrent_time + max(X- current_clears,0ll)*AB[i].second);
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
