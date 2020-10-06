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
ll BASE_NUM = 998244353;

int solve()
{
  ll n, k;
  pair<ll, ll> a, b;
  scanf("%lld", &n);
  scanf("%lld", &k);
  scanf("%lld", &a.first);
  scanf("%lld", &a.second);
  scanf("%lld", &b.first);
  scanf("%lld", &b.second);
  if (a > b)
  {
    swap(a, b);
  }
  // cout << a.second << "|" << b.first << endl;
  if (a.second <= b.first)
  {
    ll touch = b.first - a.second;
    ll d = b.second - a.first;
    if ( d == 0 ){
      cout << 2 * k << "\n";
    }else{
      ll times = k / d;
      ll remain = k % d;

      if (times <= n)
      {
        if (touch + remain < 2 * remain ){
          cout << (touch + d) * times + touch + remain << "\n";
        }else{
          cout << (touch + d) * times + 2 * remain << "\n";
        }
      }
      else
      {
        cout << (touch + d) * n + 2 * (k - n * d) << "\n";
      }
    }
  }
  else if (a.second <= b.second)
  {
    ll remain = k - (a.second - b.first) * n;
    if (remain <= 0)
    {
      cout << 0 << "\n";
    }
    else
    {
      ll ab_remain_size = n * ((b.second - a.first ) - (a.second - b.first));
      if ( ab_remain_size >= remain){
        cout << remain << "\n";
      }else{
        cout << ab_remain_size + 2 * (remain - ab_remain_size) << "\n";
      }
    }
  }
  else
  {
    ll remain = k - (b.second - b.first) * n;
    if (remain <= 0)
    {
      cout << 0 << "\n";
    }
    else
    {
      ll a_remain_size = n * ((a.second - a.first) - (b.second - b.first));
      if (a_remain_size >= remain)
      {
        cout << remain << "\n";
      }
      else
      {
        cout << a_remain_size + 2 * (remain - a_remain_size) <　< "\n";
      }
    }
  }
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