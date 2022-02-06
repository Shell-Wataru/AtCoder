#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll counts(ll L, ll N)
{
  for (int i = 60; i >= 0; i--)
  {
    if ((L & 1ll << i) && (N & 1ll << i))
    {
      return L - (1ll<<i) + 1 + counts((1ll<<i) - 1,N);
    }
    else if ((L & 1ll << i) && !(N & 1ll << i))
    {
      return counts((1ll<<i) - 1,N);
    }
    else if (!(L & 1ll << i) && (N & 1ll << i))
    {
      continue;
    }
    else
    {
      continue;
    }
  }

  return 0;
}
int solve()
{
  ll L, R, N;
  cin >> N >> L >> R;
  // cout << counts(R, N) << endl;
  // cout << counts(L-1, N) << endl;
  cout << counts(R, N) - counts(L-1, N) << endl;
  return 0;
}
int main()
{
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  // cout << flush;
  return 0;
}