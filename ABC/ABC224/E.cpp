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
#include <set>
using namespace std;
using ll = long long;

int main()
{
  ll H, W, N;
  cin >> H >> W >> N;
  vector<ll> first_minimum_rows(H, numeric_limits<ll>::max());
  vector<ll> first_minimum_row_values(H, -1);
  vector<ll> second_minimum_row_values(H, -1);
  vector<ll> first_minimum_columns(W, numeric_limits<ll>::max());
  vector<ll> first_minimum_column_values(W, -1);
  vector<ll> second_minimum_column_values(W, -1);
  priority_queue<pair<ll, pair<ll, ll>>> points_queue;
  vector<pair<ll, ll>> points(N);
  for (int i = 0; i < N; i++)
  {
    ll r, c, a;
    cin >> r >> c >> a;
    r--;
    c--;
    points_queue.push({a, {r, c}});
    points[i] = {r, c};
  }
  map<pair<ll, ll>, ll> ans;
  while (!points_queue.empty())
  {
    auto p = points_queue.top();
    points_queue.pop();
    ll r = p.second.first;
    ll c = p.second.second;
    ll a = p.first;
    ll value = 0;
    if (a < first_minimum_rows[r])
    {
      value = max(value, first_minimum_row_values[r] + 1);
    }
    else
    {
      value = max(value, second_minimum_row_values[r] + 1);
    }
    if (a < first_minimum_columns[c])
    {
      value = max(value, first_minimum_column_values[c] + 1);
    }
    else
    {
      value = max(value, second_minimum_column_values[c] + 1);
    }

    ans[{r, c}] = value;

    if (a < first_minimum_rows[r])
    {
      second_minimum_row_values[r] = first_minimum_row_values[r];
      first_minimum_rows[r] = a;
      first_minimum_row_values[r] = value;
    }
    else
    {
      first_minimum_row_values[r] = max(first_minimum_row_values[r],value);
    }

    if (a < first_minimum_columns[c])
    {
      second_minimum_column_values[c] = first_minimum_column_values[c];
      first_minimum_columns[c] = a;
      first_minimum_column_values[c] = value;
    }
    else
    {
      first_minimum_column_values[c] = max(first_minimum_column_values[c],value);
    }
  }
  for (int i = 0; i < N; i++)
  {
    cout << ans[points[i]] << endl;
  }
  return 0;
}
