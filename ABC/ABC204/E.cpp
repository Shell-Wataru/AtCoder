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

ll three_search(ll l, ll r, ll D)
{
  // cout << l << "~" << r << endl;
  if (l + 2 == r)
  {
    ll t1 = l;
    ll t2 = l + 1;
    ll t3 = l + 2;
    ll t1_value = t1 + D / (t1 + 1);
    ll t2_value = t2 + D / (t2 + 1);
    ll t3_value = t3 + D / (t3 + 1);
    if (t1_value <= t2_value && t1_value <= t3_value)
    {
      return t1;
    }
    else if (t2_value <= t3_value && t2_value <= t1_value)
    {
      return t2;
    }
    else
    {
      return t3;
    }
  }
  else
  {
    ll t1 = (2 * l + r) / 3;
    ll t2 = (l + 2 * r) / 3;
    ll t1_value = t1 + D / (t1 + 1);
    ll t2_value = t2 + D / (t2 + 1);
    if (t1_value <= t2_value)
    {
      return three_search(l, t2, D);
    }
    else
    {
      return three_search(t1, r, D);
    }
  }
}

int main()
{
  ll N, M;
  cin >> N >> M;
  vector<vector<vector<ll>>> G(N);
  for (int i = 0; i < M; i++)
  {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    G[a].push_back({b, c, d});
    G[b].push_back({a, c, d});
  }
  vector<ll> min_d(N, numeric_limits<ll>::max());
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push({0, 0});
  // cout << "!!" << endl;
  while (!q.empty())
  {
    auto d = q.top();
    q.pop();
    ll current = d.second;
    ll value = d.first;
    // cout << current << ":" << value << endl;
    if (value >= min_d[current])
    {
      continue;
    }
    min_d[current] = value;
    for (auto &e : G[current])
    {
      ll t = three_search(value, numeric_limits<ll>::max() / 4, e[2]);
      q.push({t + e[1] + e[2] / (t + 1), e[0]});
    }
  }
  if (min_d[N - 1] == numeric_limits<ll>::max())
  {
    cout << -1 << endl;
  }
  else
  {
    cout << min_d[N - 1] << endl;
  }

  return 0;
}
