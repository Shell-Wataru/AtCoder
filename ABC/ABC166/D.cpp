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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;
ll factor(ll a, ll b)
{
  return a * a * a * a + b * a * a * a + b * b * a * a + b * b * b * a + b * b * b * b;
}

ll solve(ll X, ll diff)
{
  ll min_a = (diff + 1) / 2;
  ll min_b = -diff / 2;
  while (factor(min_a,min_b) < X / diff)
  {
    min_a++;
    min_b++;
  }
  return min_b;
}
int main()
{
  // 整数の入力
  ll X;
  cin >> X;
  vector<ll> factors;
  for (int i = 1; i * i <= X; i++)
  {
    if (X % i == 0)
    {
      factors.push_back(i);
      factors.push_back(X / i);
    }
  }
  ll A = 0;
  ll B = 0;
  for (auto diff : factors)
  {
    ll min_upper_b = solve(X, diff);
    if (factor(min_upper_b + diff,min_upper_b) == X / diff)
    {
      A = min_upper_b + diff;
      B = min_upper_b;
    }
  }
  cout << A << " " << B << endl;
  return 0;
}