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
int BASE_NUM = 998244353;


int solve()
{
  ll n, k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  vector<vector<ll>> A(n, vector<ll>(n, 0));
  ll row_ones = (k+ n-1) /n;
  ll optimal = row_ones;
  while(optimal != n ){
    if (n % optimal == 0 || n % (n - optimal) == 0){
      break;
    }
    optimal++;
  }
  if (optimal <= n - optimal){
    for(int i = 0; i < n/optimal;i++){
      for(int j = 0;j < optimal;j++){
        for(int k = 0;k < optimal;k++){
          A[i*optimal + j][i* optimal +k] = 1;
        }
      }
    }
    for(int i = 0; i< optimal * n - k;i++){
      A[i][i] = 0;
    }
  }else{
    A = vector<vector<ll>>(n,vector<ll>(n,1));
    for(int i = 0; i < n/(n-optimal);i++){
      for(int j = 0;j < (n-optimal);j++){
        for(int k = 0;k < (n-optimal);k++){
          A[i*(n-optimal) + j][i* (n-optimal) +k] = 0;
        }
      }
    }
    for(int i = 0; i< optimal * n - k;i++){
      // cout << "i" << i << endl;
      A[i][(i + optimal) % n] = 0;
    }
  }
  ll row_max = 0;
  ll row_min = numeric_limits<ll>::max();
  for (int i = 0; i < n; i++)
  {
    ll row = 0;
    for (int j = 0; j < n; j++)
    {
      row += A[i][j];
    }
    row_max = max(row_max, row);
    row_min = min(row_min, row);
  }
  ll column_max = 0;
  ll column_min = numeric_limits<ll>::max();
  for (int i = 0; i < n; i++)
  {
    ll column = 0;
    for (int j = 0; j < n; j++)
    {
      column += A[j][i];
    }
    column_max = max(column_max, column);
    column_min = min(column_min, column);
  }
  cout << (column_max - column_min) * (column_max - column_min) + (row_max - row_min) * (row_max - row_min) << "\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << A[i][j];
    }
    cout << "\n";
  }

  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}