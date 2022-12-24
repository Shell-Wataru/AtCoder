#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n, m, k, q;
  scanf("%lld", &n);
  scanf("%lld", &m);
  scanf("%lld", &k);
  scanf("%lld", &q);
  vector<bool> remain_rows(n,true);
  vector<bool> remain_columns(m,true);
  ll remain_row_count = n;
  ll remain_column_count = m;
  vector<pair<ll, ll>> queries(q);
  for (int i = 0; i < q; i++)
  {
    ll x, y;
    scanf("%lld", &x);
    scanf("%lld", &y);
    x--;
    y--;
    queries[i] = {x, y};
  }
  ll ans = 1;
  for (int i = q - 1; i >= 0; i--)
  {
    bool is_ok;
    if (remain_row_count == 0)
    {
      // cout << "a" << endl;
      is_ok = false;
    }
    else if (remain_column_count == 0)
    {
      // cout << "b" << endl;
      is_ok = false;
    }
    else if (!remain_rows[queries[i].first] && !remain_columns[queries[i].second])
    {
      // cout << "!" << endl;
      is_ok = false;
    }
    else
    {
      is_ok = true;
    }
    if (remain_rows[queries[i].first]){
      remain_rows[queries[i].first] = false;
      remain_row_count--;
    }
    if (remain_columns[queries[i].second]){
      remain_columns[queries[i].second] = false;
      remain_column_count--;
    }
    if (is_ok)
    {
      ans = (ans * k) % 998244353;
    }
  }
  cout << ans << "\n";
  return 0;
}

int main()
{
  int t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}