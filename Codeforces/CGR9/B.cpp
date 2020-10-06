#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> A(n,vector<ll>(m));
  vector<vector<ll>> B(n,vector<ll>(m));
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      cin >> A[i][j];
    }
  }

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      if ( (i == 0  || i == n - 1) && (j == 0  || j == m - 1)){
        B[i][j] = 2;
      }else if (i == 0  || i == n - 1){
        B[i][j] = 3;
      }else if (j == 0  || j == m - 1){
        B[i][j] = 3;
      }else{
        B[i][j] = 4;
      }
    }
  }
  bool can_make = true;
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      if (B[i][j] < A[i][j]){
        can_make = false;
      }
    }
  }
  if (can_make){
    cout << "YES" << "\n";
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        if (j != 0){
          cout << " ";
        }
        cout << B[i][j];
      }
      cout << "\n";
    }
  }else{
    cout << "NO" << "\n";
  }
  cout << flush;
  return 0;
}
int main()
{
  ll t;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  return 0;
}
