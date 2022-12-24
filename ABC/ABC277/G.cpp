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
#include <atcoder/mincostflow>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

int main()
{
  ll N;
  cin >> N;
  vector<vector<ll>> Abigger;
  vector<vector<ll>> Bbigger;
  vector<vector<ll>> Same;

  for (int i = 0; i < N; i++)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
      Abigger.push_back({a, b, c});
    }
    else if (b > a)
    {
      Bbigger.push_back({a, b, c});
    }
    else
    {
      Same.push_back({a, b, c});
    }
  }
  double ans = 0;
  for (auto v : Same)
  {
    ans = max(ans, 1.0 * v[2] / v[0]);
  }
  sort(Abigger.begin(), Abigger.end(), [](vector<ll> &l, vector<ll> &r)
       { return (r[0] + r[1]) * l[2] > (l[0] + l[1]) * r[2]; });
  sort(Bbigger.begin(), Bbigger.end(), [](vector<ll> &l, vector<ll> &r)
       { return (r[0] + r[1]) * l[2] > (l[0] + l[1]) * r[2]; });

  for (int i = 0; i < Bbigger.size(); i++)
  {
    ans = max(ans, 1.0 * Bbigger[i][2] / Bbigger[i][1]);
    for (int j = 0; j < min((ll)Abigger.size(), 10ll); j++)
    {
      ll a_diff = Abigger[j][0] - Abigger[j][1];
      ll b_diff = Bbigger[i][1] - Bbigger[i][0];
      ans = max(ans, 1.0 * (b_diff / gcd(a_diff, b_diff) * Abigger[j][2] + a_diff / gcd(a_diff, b_diff) * Bbigger[i][2]) / (b_diff / gcd(a_diff, b_diff) * Abigger[j][0] + a_diff / gcd(a_diff, b_diff) * Bbigger[i][0]));
    }
  }

  for (int i = 0; i < Abigger.size(); i++)
  {
    ans = max(ans, 1.0 * Abigger[i][2] / Abigger[i][0]);
    for (int j = 0; j < min((ll)Bbigger.size(), 10ll); j++)
    {
      ll a_diff = Abigger[i][0] - Abigger[i][1];
      ll b_diff = Bbigger[j][1] - Bbigger[j][0];
      ans = max(ans, 1.0 * (b_diff / gcd(a_diff, b_diff) * Abigger[i][2] + a_diff / gcd(a_diff, b_diff) * Bbigger[j][2]) / (b_diff / gcd(a_diff, b_diff) * Abigger[i][0] + a_diff / gcd(a_diff, b_diff) * Bbigger[j][0]));
    }
  }
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}
