#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cmath>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<pair<ll,ll>> A(n);
  vector<pair<ll,ll>> B(n);
  for(int i = 0;i < n;i++){
      cin >> A[i].first >> A[i].second;
  }
  for(int i = 0;i < n;i++){
      cin >> B[i].first >> B[i].second;
  }
  double a_center_x = 0;
  double a_center_y = 0;
  for(int i = 0;i < n;i++){
      a_center_x += A[i].first;
      a_center_y += A[i].second;
  }
  a_center_x /= n;
  a_center_y /= n;
  double b_center_x = 0;
  double b_center_y = 0;
  for(int i = 0;i < n;i++){
      b_center_x += B[i].first;
      b_center_y += B[i].second;
  }
  b_center_x /= n;
  b_center_y /= n;
  double a_farthest = 0;
  for(int i = 0;i < n;i++){
      a_farthest = max(a_farthest,hypot(a_center_x - A[i].first,a_center_y - A[i].second));
  }
  double b_farthest = 0;
  for(int i = 0;i < n;i++){
      b_farthest = max(b_farthest,hypot(b_center_x - B[i].first,b_center_y - B[i].second));
  }
  cout <<  fixed << setprecision(12)<< b_farthest/a_farthest << endl;
  return 0;
}

int main()
{
  // // 整数の入力
//   ll t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
    solve();
//   }
//   cout << flush;
  return 0;
}
