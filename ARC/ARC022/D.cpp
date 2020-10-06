#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

//https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
#include <random>
using namespace std;
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

ll cross(pair<ll, ll> &O, pair<ll, ll> &A, pair<ll, ll> &B)
{
  return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<pair<ll, ll>> convex_hull(vector<pair<ll, ll>> &P)
{
  size_t n = P.size(), k = 0;
  if (n <= 3)
    return P;
  vector<pair<ll, ll>> H(2 * n);

  // Sort points lexicographically
  sort(P.begin(), P.end());

  // Build lower hull
  for (size_t i = 0; i < n; ++i)
  {
    while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
      k--;
    H[k++] = P[i];
  }

  // Build upper hull
  for (size_t i = n - 1, t = k + 1; i > 0; --i)
  {
    while (k >= t && cross(H[k - 2], H[k - 1], P[i - 1]) <= 0)
      k--;
    H[k++] = P[i - 1];
  }

  H.resize(k - 1);
  return H;
}

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<pair<ll, ll>> P(N);
  vector<vector<pair<ll, ll>>> ranges(500000);
  for (int i = 0; i < N; i++)
  {
    cin >> P[i].first >> P[i].second;
  }
  P.push_back({0, 0});
  vector<pair<ll, ll>> convex = convex_hull(P);
  ll center = 250000;
  for (auto &p : convex)
  {
    // cout << "x:" <<p.first << " y:" << p.second << endl;
    ll r2 = p.first * p.first + p.second * p.second;
    ll d = 0;
    ll width = sqrt(r2) + 1;
    while (d * d <= r2)
    {
      while (width * width > r2 - d * d)
      {
        width--;
      }
      ranges[p.second + d + center].emplace_back(p.first - width, p.first + width + 1);
      ranges[p.second - d + center].emplace_back(p.first - width, p.first + width + 1);
      d++;
    }
  }
  ll total = 0;
  for (int i = 0; i < 500000; i++)
  {
    sort(ranges[i].begin(), ranges[i].end());
    ll from = -BASE_NUM;
    ll to = -BASE_NUM;
    for (auto &p : ranges[i])
    {
      // cout << i - center << ":" << p.first << "~" << p.second - 1 << endl;
      if (to < p.first)
      {
        total += to - from;
        from = p.first;
        to = p.second;
      }
      else
      {
        to = max(p.second, to);
      }
    }

    total += to - from;
  }
  cout << total << endl;
  return 0;
}