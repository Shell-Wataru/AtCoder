#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
  ll n, m;
  scanf("%lld", &n);
  scanf("%lld", &m);
  vector<ll> a(n);
  vector<ll> b(m);
  for (int i = 1; i <= n; i++)
  {
    scanf("%lld", &a[i]);
  }
  for (int i = 1; i <= m; i++)
  {
    scanf("%lld", &b[i]);
  }
  sort(b.begin(),b.end());
  for
  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
