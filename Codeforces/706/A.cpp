#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  scanf("%lld",&n);
  vector<ll> miners;
  vector<ll> mines;
  for(int i = 0;i < 2*n;i++){
    ll x,y;
    cin >> x >> y;
    if (x == 0){
      miners.push_back(abs(y));
    }else{
      mines.push_back(abs(x));
    }
  }
  sort(miners.begin(),miners.end());
  sort(mines.begin(),mines.end());
  double ans = 0;
  for(int i = 0;i < n;i++){
    ans += hypot(miners[i],mines[i]);
  }
  cout << setprecision(16) << ans;
  cout << "\n";

  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}