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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> odds;
  vector<ll> evens;
  for (size_t i = 0; i < 2*n; i++)
  {
    ll a;
    cin >> a;
    if (a % 2 == 0)
    {
      evens.push_back(i+1);
    }
    else
    {
      odds.push_back(i+1);
    }
  }
  vector<pair<ll,ll>> pairs;
  for (int i = 0; 2 * i + 1 < odds.size(); i++)
  {
    pairs.push_back({odds[2 * i] ,odds[2 * i + 1]});
  }
  for (int i = 0; 2 * i + 1 < evens.size(); i++)
  {
    pairs.push_back({evens[2 * i] ,evens[2 * i + 1]});
  }
  for (int i = 0; i < n-1; i++)
  {
    cout << pairs[i].first << " " << pairs[i].second << "\n";
  }
  cout << flush;
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
  return 0;
}
