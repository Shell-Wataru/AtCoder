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

int solve()
{
  ll N, M;
  cin >> N >> M;
  ll maximum = numeric_limits<ll>::min();
  ll sum_c = 0;
  ll current_a = 0;
  for (int i = 0; i < N; i++)
  {
    ll x, y;
    cin >> x >> y;
    if (i == 0)
    {
      maximum = x;
    }
    if (sum_c > 0 && x < 0 && sum_c/(-x) < y){
      ll take = sum_c/(-x);
      maximum = max(maximum, current_a + sum_c * take + x * take *(take+1)/2);
    }
    ll newbie = x * y * (y + 1) / 2;
    current_a += sum_c * y + newbie;
    sum_c += x * y;
    maximum = max(maximum, current_a);
  }
  cout << maximum << "\n";
  return 0;
}

int main()
{
  ll T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
