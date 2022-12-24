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

using namespace std;
using ll = long long;

ll answer(vector<pair<ll, ll>> &P, vector<ll> &A, ll l, ll r)
{
  if (l + 1 == r)
  {
    return r;
  }
  // cout << l << "~" << r << endl;
  ll N = P.size();
  ll center = (l + r) / 2;
  vector<bool> visited(N, false);
  for (auto a : A)
  {
    for (auto i = 0; i < N; i++)
    {
      ll dx = P[i].first - P[a].first;
      ll dy = P[i].second - P[a].second;
      if (dx * dx + dy * dy <= center)
      {
        visited[i] = true;
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (!visited[i])
    {
      return answer(P, A, center, r);
    }
  }
  return answer(P, A, l, center);
}
int main()
{
  // 整数の入力
  ll N, K;
  cin >> N >> K;
  vector<pair<ll, ll>> P(N);
  vector<ll> A(K);
  for (int i = 0; i < K; i++)
  {
    cin >> A[i];
    A[i]--;
  }
  for (int i = 0; i < N; i++)
  {
    cin >> P[i].first >> P[i].second;
  }

  ll dd = answer(P, A, 0, numeric_limits<ll>::max() / 2);
  // cout << dd << endl;
  cout << fixed << setprecision(12) << sqrt(dd) << endl;
  return 0;
}