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

ll min_value(vector<ll> &red, vector<ll> &blue, vector<ll> &green)
{
  ll ans = numeric_limits<ll>::max();
  for (auto r : red)
  {
    auto itr = lower_bound(blue.begin(), blue.end(), r);
    if (itr != blue.end())
    {
      ans = min(ans, abs(*itr - r));
    }
    if (itr != blue.begin())
    {
      itr--;
      ans = min(ans, abs(*itr - r));
    }
  }
  // cout << ans << endl;
  ll rg_min = numeric_limits<ll>::max()/2;
  for (auto r : red)
  {
    auto itr = lower_bound(green.begin(), green.end(), r);
    if (itr != green.end())
    {
      rg_min = min(rg_min, abs(*itr - r));
    }
    if (itr != green.begin())
    {
      itr--;
      rg_min = min(rg_min, abs(*itr - r));
    }
  }

  ll bg_min = numeric_limits<ll>::max()/2;
  for (auto b : blue)
  {
    auto itr = lower_bound(green.begin(), green.end(), b);
    if (itr != green.end())
    {
      bg_min = min(bg_min, abs(*itr - b));
    }
    if (itr != green.begin())
    {
      itr--;
      bg_min = min(bg_min, abs(*itr - b));
    }
  }

  return min(ans, bg_min + rg_min);
}
int main()
{
  ll N;
  cin >> N;
  vector<ll> green;
  vector<ll> red;
  vector<ll> blue;
  for (int i = 0; i < 2 * N; i++)
  {
    ll a;
    char c;
    cin >> a >> c;
    if (c == 'G')
    {
      green.push_back(a);
    }
    else if (c == 'B')
    {
      blue.push_back(a);
    }
    else
    {
      red.push_back(a);
    }
  }
  sort(red.begin(), red.end());
  sort(green.begin(), green.end());
  sort(blue.begin(), blue.end());
  if (red.size() % 2 == 0 && green.size() % 2 == 0 && blue.size() % 2 == 0)
  {
    cout << 0 << endl;
  }
  else if (red.size() % 2 == 0)
  {
    cout << min_value(blue, green, red) << endl;
  }
  else if (green.size() % 2 == 0)
  {
    cout << min_value(blue, red, green) << endl;
  }
  else if (blue.size() % 2 == 0)
  {
    cout << min_value(green, red, blue) << endl;
  }
  return 0;
}