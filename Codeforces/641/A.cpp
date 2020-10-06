#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

long long gcd(long long a, long long b)
{

  if (a == 0)
  {
    return b;
  }
  else if (b == 0)
  {
    return a;
  }

  if (a % b == 0)
  {
    return b;
  }
  else
  {
    return gcd(b, a % b);
  }
}

long long lcm(long long a, long long b)
{
  return a * b / gcd(a, b);
}

map<long long, long long> decomposite(long long N, map<long long, long long> &primes, long long next_p = 2)
{
  if (N == 1)
  {
    return primes;
  }

  while (next_p * next_p <= N)
  {
    if (N % next_p == 0)
    {
      primes[next_p] += 1;
      return decomposite(N / next_p, primes, next_p);
    }
    else
    {
      next_p++;
    }
  }
  primes[N] += 1;
  return primes;
}

ll pow(ll x, ll y)
{
  if (y == 0)
  {
    return 1LL;
  }
  else
  {
    ll y_2 = pow(x, y / 2);
    ll yy = (y_2 * y_2);
    if (y % 2 == 0)
    {
      return yy;
    }
    else
    {
      return (yy * x);
    }
  }
}

int solve()
{
  ll n;
  cin >> n;
  vector<ll> A(n);
  map<ll, vector<ll>> data;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    map<ll, ll> dec_a;
    decomposite(a, dec_a);
    for (auto &p : dec_a)
    {
      data[p.first].push_back(p.second);
    }
  }
  ll ans = 1;
  for (auto &p : data)
  {

    // for(auto d:p.second){
    //   cout << d;
    // }
    // cout << endl;
    // cout << p.first << " " << p.second.size() << endl;
    if (p.second.size() <= n - 2)
    {
    }
    else if (p.second.size() == n - 1)
    {
      // cout << p.second[0] << endl;
      sort(p.second.begin(), p.second.end());
      ans *= pow(p.first, p.second[0]);
    }
    else
    {
      // cout << p.second[0] + p.second[1] << endl;
      sort(p.second.begin(), p.second.end());
      ans *= pow(p.first, p.second[1]);
    }
  }
  cout << ans << endl;
  return 0;
}

int main()
{
  // 整数の入力
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
  solve();
  // }
  return 0;
}