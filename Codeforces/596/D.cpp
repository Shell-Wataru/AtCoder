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

ll my_pow(ll x, ll y)
{
  if (y == 0)
  {
    return 1LL;
  }
  else if (y == 1)
  {
    return x;
  }
  else
  {
    return (my_pow(x, y / 2) % BASE_NUM) * (my_pow(x, (y + 1) / 2) % BASE_NUM) % BASE_NUM;
  }
}

bool is_complete(ll k, map<ll, ll> &decomp)
{
  bool is_comp = true;
  for (auto p : decomp)
  {
    if (p.second != k)
    {
      is_comp = false;
      break;
    }
  }
  return is_comp;
}

string hash_key( map<ll, ll> &decomp){
  string s = "";
  for (auto p : decomp)
  {
    s += "," + to_string(p.first) + ":" + to_string(p.second);
  }
  return s;
}
int main()
{
  ll n, k;
  map<string, ll> data;
  ll total = 0;
  ll completes = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    ll a;
    map<ll, ll> decomp;
    cin >> a;
    decomposite(a, decomp);
    if (a == 1)
    {
      total += completes;
      completes++;
    }
    else if (is_complete(k, decomp))
    {
      total += completes;
      completes++;
    }
    else
    {
      if (data[hash_key(decomp)] > 0)
      {
        cout << a << endl;
      }
      total += data[hash_key(decomp)];
    }
    data[hash_key(decomp)]++;
  }
  cout << total << endl;
  return 0;
}