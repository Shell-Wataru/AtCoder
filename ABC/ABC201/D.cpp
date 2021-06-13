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

using namespace std;
using ll = long long;

ll min_square(vector<vector<ll>> &A, ll N, ll K, ll l, ll r)
{
  // cout << l << " " << r << endl;
  if (l + 1 == r)
  {
    return r;
  }
  ll center = (l + r) / 2;
  vector<vector<ll>> ruisekiWaLT(N + 1, vector<ll>(N + 1, 0));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (A[i][j] <= center)
      {
        ruisekiWaLT[i + 1][j + 1] = 1 + ruisekiWaLT[i + 1][j] + ruisekiWaLT[i][j + 1] - ruisekiWaLT[i][j];
      }
      else
      {
        ruisekiWaLT[i + 1][j + 1] = ruisekiWaLT[i + 1][j] + ruisekiWaLT[i][j + 1] - ruisekiWaLT[i][j];
      }
    }
  }

  // for(int i = 0;i <N;i++){
  //   for(int j = 0;j < N;j++){
  //     if (A[i][j] <= center){
  //       ruisekiWaLTE[i+1][j+1] = 1 + ruisekiWaLTE[i+1][j]  + ruisekiWaLTE[i][j+1] - ruisekiWaLTE[i][j];
  //     }else{
  //       ruisekiWaLTE[i+1][j+1] = ruisekiWaLTE[i+1][j]  + ruisekiWaLTE[i][j+1] - ruisekiWaLTE[i][j];
  //     }
  //   }
  // }
  // for(int i = 0;i <N;i++){
  //   for(int j = 0;j < N;j++){
  //     cout << ruisekiWaLT[i+1][j+1] << ",";
  //   }
  //   cout << endl;
  // }
  ll max_total = numeric_limits<ll>::min();
  for (int i = 0; i + K - 1 < N; i++)
  {
    for (int j = 0; j + K - 1 < N; j++)
    {
      max_total = max(max_total, ruisekiWaLT[i + K][j + K] - ruisekiWaLT[i][j + K] - ruisekiWaLT[i + K][j] + ruisekiWaLT[i][j]);
    }
  }
  // cout << K*K/2 + 1 << endl;
  // cout << center << ":" << max_total<< endl;
  if (max_total >= (K * K + 1) / 2)
  {
    return min_square(A, N, K, l, center);
  }
  else
  {
    return min_square(A, N, K, center, r);
  }
}
int main()
{
  // 整数の入力
  ll N, K;
  cin >> N >> K;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> A[i][j];
    }
  }
  cout << min_square(A, N, K, -1, numeric_limits<ll>::max() / 2) << endl;
  return 0;
}
