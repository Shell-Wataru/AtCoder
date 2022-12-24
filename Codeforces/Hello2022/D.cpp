#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int solve()
{
  ll n;
  cin >> n;
  vector<vector<ll>> scores(2*n,vector<ll>(2*n));
  for(int i = 0;i < 2*n;i++){
    for(int j = 0;j < 2*n;j++){
      scanf("%lld",&scores[i][j]);
    }
  }
  ll ans = 0;
  for(int i = n;i < 2*n;i++){
    for(int j = n;j < 2*n;j++){
      ans += scores[i][j];
    }
  }
  ll other = numeric_limits<ll>::max();
  other = min(other,scores[n][0]);
  other = min(other,scores[n][n-1]);
  other = min(other,scores[2*n-1][0]);
  other = min(other,scores[2*n-1][n-1]);
  other = min(other,scores[0][n]);
  other = min(other,scores[n-1][n]);
  other = min(other,scores[0][2*n-1]);
  other = min(other,scores[n-1][2*n-1]);

  ans += other;
  cout << ans << "\n";
  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}