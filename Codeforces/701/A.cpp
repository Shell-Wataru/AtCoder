#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;
using ll = long long;

ll value(ll a, ll b, ll add)
{
  ll ans = add;
  ll divide = b + add;
  if (divide == 1)
  {
    return numeric_limits<ll>::max();
  }
  while (a > 0)
  {
    a /= divide;
    ans++;
  }
  return ans;
}

ll three_search(ll a, ll b, ll l, ll r)
{

  ll t1 = (2 * l + r) / 3;
  ll t2 = (l + 2 * r) / 3;
  ll t1_value = value(a, b, t1);
  ll t2_value = value(a, b, t2);
  cout << "==" << endl;
  cout << l << " " << r << endl;
  cout << t1 << " " << t2 << endl;
  cout << t1_value << " " << t2_value << endl;
  if (l + 2 == r)
  {
    if (t1_value <= t2_value)
    {
      return t1;
    }
    else
    {
      return t2;
    }
  }
  else
  {
    if (t1_value <= t2_value)
    {
      return three_search(a, b, l, t2);
    }
    else
    {
      return three_search(a, b, t1, r);
    }
  }
}

int solve()
{
  ll a, b;
  cin >> a >> b;
  ll add = three_search(a, b, 0, a+1);
  cout << value(a, b, add) << "\n";
  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}