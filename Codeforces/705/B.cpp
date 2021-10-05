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
const ll BASE_NUM = 1000000007;

bool is_after_or_equal(ll h, ll m, ll h0, ll h1, ll m0, ll m1)
{
  return h0 * 1000 + h1 * 100 + m0 * 10 + m1 >= 100 * h + m;
}

bool is_valid(ll h, ll m, ll h0, ll h1, ll m0, ll m1)
{
  return h0 * 10 + h1 < h && m0 * 10 + m1 < m;
}

bool mirror_is_valid(map<ll,ll> &correspondence, ll h, ll m, ll h0, ll h1, ll m0, ll m1)
{
  return correspondence[m1] * 10 + correspondence[m0] < h && correspondence[h1] * 10 + correspondence[h0] < m;
}
int solve()
{
  ll h,m;
  cin >> h;
  cin >> m;
  string S;
  cin >> S;
  ll current_h = 10 * (S[0] - '0') + (S[1] - '0');
  ll current_m = 10 * (S[3] - '0') + (S[4] - '0');

  // cout << h << endl;
  // cout << m << endl;
  // cout << S << endl;
  // cout << current_h << endl;
  // cout << current_m << endl;
  map<ll,ll> correspondence = {
      {0, 0},
      {1, 1},
      {2, 5},
      {5, 2},
      {8, 8}};
  vector<ll> candidates = {0, 1, 2, 5, 8};
  for (auto h0 : candidates)
  {
    for (auto h1 : candidates)
    {
      for (auto m0 : candidates)
      {
        for (auto m1 : candidates)
        {
          if (is_after_or_equal(current_h, current_m, h0, h1, m0, m1) &&
              is_valid(h, m, h0, h1, m0, m1) &&
              mirror_is_valid(correspondence, h, m, h0, h1, m0, m1))
          {
            cout << h0 << h1 << ":" << m0 << m1 << "\n";
            return 0;
          }
        }
      }
    }
  }
  cout << "00:00" << "\n";
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