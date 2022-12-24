#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve()
{

  ll n;
  scanf("%lld", &n);
  vector<ll> can_make(1ll << 13, numeric_limits<ll>::max());
  can_make[0] = 0;

  for (int i = 0; i < n; i++)
  {
    ll a;
    scanf("%lld", &a);
    for (int j = 0; j < 1ll << 13; j++)
    {
      if (can_make[j] < a)
      {
        can_make[j ^ a] = min(can_make[j ^ a], a);
      }
    }
  }
  vector<ll> answers;
  for (int j = 0; j < 1ll << 10; j++)
  {
    if (can_make[j] < numeric_limits<ll>::max())
    {
      answers.push_back(j);
    }
  }
  cout << answers.size() << "\n";
  for (auto a : answers)
  {
    cout << a << " ";
  }
  cout << "\n";
  return 0;
}
int main()
{
  // int t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  cout << flush;
  return 0;
}