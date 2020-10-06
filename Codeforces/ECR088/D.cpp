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
  vector<ll> A(n);
  vector<vector<ll>> DP(n, vector<ll>(61, - BASE_NUM));
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }

  ll max_score = 0;
  DP[0][A[0] + 30] = A[0];
  for (int i = 1; i < n; i++)
  {
    ll before_max_score = - BASE_NUM;
    for (int j = -30; j <= 30; j++)
    {
      before_max_score = max(before_max_score, DP[i - 1][j+30]);
      if (A[i] > j)
      {
        DP[i][j + 30] = -BASE_NUM;
      }
      else
      {
        DP[i][j + 30] = max(before_max_score + A[i],A[i]);
        max_score = max(max_score, DP[i][j + 30] - j);
      }
      // cout << i << "," << j << ":" << DP[i][j+30] << endl;
    }
  }
  cout << max_score << endl;
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  // cout << flush;
  return 0;
}