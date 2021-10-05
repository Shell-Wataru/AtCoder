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
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

bool can_make(string &s)
{
  ll t_count = 0;
  ll m_count = 0;
  bool ret = true;
  for (auto c : s)
  {
    if (c == 'T')
    {
      t_count++;
    }
    else
    {
      m_count++;
      if (t_count < m_count)
      {
        ret = false;
      }
    }
  }
  if (m_count * 2 != t_count)
  {
    ret = false;
  }
  return ret;
}
int solve()
{
  ll n;
  scanf("%lld", &n);
  string s;
  cin >> s;
  string rev_s(s.rbegin(),s.rend());
  if (can_make(s) && can_make(rev_s))
  {
    cout << "YES\n";
  }
  else
  {
    cout << "NO\n";
  }
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
  cout << flush;
  return 0;
}