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
  ll Q;
  cin >> Q;
  deque<pair<ll,ll>> q;
  for(int i = 0;i < Q;i++){
    ll t;
    cin >> t;
    if( t== 1){
      ll x,c;
      cin >> x >> c;
      q.push_back({x,c});
    }else{
      ll c;
      cin >> c;
      ll ans = 0;
      while(c > 0){
        ll take = min(q.front().second,c);
        ans += q.front().first * take;
        q.front().second -= take;
        if (q.front().second == 0){
          q.pop_front();
        }
        c -= take;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}

int main()
{
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
