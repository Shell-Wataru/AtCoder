#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{

  ll n, m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<ll> x(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }
  vector<string> s(n);
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  ll ans = 0;
  vector<ll> ans_vector;
  for (int i = 0; i < 1ll << n; i++)
  {
    vector<pair<ll, ll>> clear_counts(m);
    for (int j = 0; j < m; j++)
    {
      clear_counts[j] = {0, j};
      for (int k = 0; k < n; k++)
      {
        if (s[k][j] == '1')
        {
          if (i & 1ll<<k){
            clear_counts[j].first++;
          }else{
            clear_counts[j].first--;
          }
        }
      }
    }
    sort(clear_counts.begin(), clear_counts.end());
    ll current = 0;
    for (int k = 0; k < n; k++)
    {
      ll r = 0;
      for (int j = 0; j < m; j++)
      {
        if (s[k][clear_counts[j].second] == '1')
        {
          r += j + 1;
        }
      }
      current += abs(x[k] - r);
    }
    if (current > ans)
    {
      ans = current;
      ans_vector = vector<ll>(m);
      for (int j = 0; j < m; j++)
      {
        ans_vector[clear_counts[j].second] = j + 1;
      }
    }
  }
  for (auto a : ans_vector)
  {
    cout << a << " ";
  }
  cout << "\n";
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