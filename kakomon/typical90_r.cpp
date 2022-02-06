#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>

using namespace std;
using ll = long long;

int solve()
{
  ll T,L,X,Y,Q;
  scanf("%lld", &T);
  scanf("%lld", &L);
  scanf("%lld", &X);
  scanf("%lld", &Y);
  scanf("%lld", &Q);
  for(int i = 0;i < Q;i++){
      ll t;
      cin >> t;
      t %= T;
      double x =  X;
      double y =  Y + sin(2.0 * M_PI *t/T) * L / 2;
      double z =  L/2.0 - cos(2.0 * M_PI *t/T) * L / 2;
      cout << fixed << setprecision(12) << atan(z/hypot(x,y)) /M_PI * 180 << "\n";
  }
  return 0;
}

int main()
{
//   int t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
  solve();
//   }
  cout << flush;
  return 0;
}