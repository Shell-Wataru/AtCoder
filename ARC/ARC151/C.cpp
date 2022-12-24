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
#include <unordered_map>

using namespace std;
using ll = long long;

int main()
{
  ll N, M, K;
  cin >> N >> M;
  ll grundy = 0;
  map<ll, ll> XY;
  for (int i = 0; i < M; i++)
  {
    ll x, y;
    cin >> x >> y;
    XY[x] = y;
  }
  ll last_value = -1;
  ll last_index = -1;
  for (auto p : XY)
  {
    if (last_index == -1)
    {
      grundy ^= p.first - 1;
      last_value = p.second;
      last_index = p.first;
    }
    else if (last_value == p.second)
    {
      grundy ^= 1;
      last_value = p.second;
      last_index = p.first;
    }
    else
    {
      grundy ^= 0;
      last_value = p.second;
      last_index = p.first;
    }
  }
  if (last_index == -1)
  {
    grundy ^= N%2;
  }
  else
  {
    grundy ^= N - last_index;
  }
  // cout << grundy << endl;
  if (grundy > 0)
  {
    cout << "Takahashi" << endl;
  }
  else
  {
    cout << "Aoki" << endl;
  }
  return 0;
}
