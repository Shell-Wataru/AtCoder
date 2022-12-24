#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

int solve()
{
  ll n, x, y;
  scanf("%lld", &n);
  scanf("%lld", &x);
  scanf("%lld", &y);
  string a, b;
  cin >> a >> b;
  ll a_one_count = 0;
  ll b_one_count = 0;
  for (auto c : a)
  {
    if (c == '1')
    {
      a_one_count++;
    }
  }
  for (auto c : b)
  {
    if (c == '1')
    {
      b_one_count++;
    }
  }
  if ((a_one_count + b_one_count) % 2 != 0)
  {
    cout << -1 << "\n";
  }
  else
  {
    if (y <= x)
    {
      ll change_count = 0;
      bool last_neighbor = false;
      for (int i = 0; i < n; i++)
      {
        if (a[i] != b[i])
        {
          change_count++;
          if (i > 0 && a[i - 1] != b[i - 1])
          {
            last_neighbor = true;
          }
        }
      }
      if (change_count == 2 && last_neighbor)
      {
        cout << min(x, 2 * y) << "\n";
      }
      else
      {
        cout << change_count / 2 * y << "\n";
      }
    }else{
      vector<vector<ll>> DP(4,vector<ll>(n+1,numeric_limits<ll>::max()/2));
      DP[0][0] = 0;
      for(int i = 0;i < n;i++){
        if (a[i] != b[i]){
          DP[0][i+1] = min(DP[0][i+1],DP[1][i] + x);
          DP[0][i+1] = min(DP[0][i+1],DP[2][i] + y);
        }else{
          DP[0][i+1] = min(DP[0][i+1],DP[0][i]);
        }

        if (a[i] != b[i]){
          DP[1][i+1] = min(DP[1][i+1],DP[0][i]);
        }else{
          DP[1][i+1] = min(DP[1][i+1],DP[1][i] + x);
          DP[1][i+1] = min(DP[1][i+1],DP[2][i] + y);
        }

        if (i > 0){
          if (a[i] != b[i]){
            DP[2][i+1] = min(DP[2][i+1],DP[0][i] + x);
            DP[2][i+1] = min(DP[2][i+1],DP[3][i] + x);
          }else{
            DP[2][i+1] = min(DP[2][i+1],DP[1][i]);
            DP[2][i+1] = min(DP[2][i+1],DP[2][i]);
          }
        }

        if (i > 0){
          if (a[i] != b[i]){
            DP[3][i+1] = min(DP[3][i+1],DP[2][i]);
          }else{
            DP[3][i+1] = min(DP[3][i+1],DP[3][i] + x);
          }
        }
      }
      // for(int i = 0;i <= n;i++){
      //   if (DP[0][i] != numeric_limits<ll>::max()/2){
      //     cout << DP[0][i] << ",";
      //   }else{
      //     cout << "x,";
      //   }
      // }
      // cout << endl;
      // for(int i = 0;i <= n;i++){
      //   if (DP[1][i] != numeric_limits<ll>::max()/2){
      //     cout << DP[1][i] << ",";
      //   }else{
      //     cout << "x,";
      //   }
      // }
      // cout << endl;
      // for(int i = 0;i <= n;i++){
      //   if (DP[2][i] != numeric_limits<ll>::max()/2){
      //     cout << DP[2][i] << ",";
      //   }else{
      //     cout << "x,";
      //   }
      // }
      // cout << endl;
      cout << DP[0][n] << "\n";
    }
  }

  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
