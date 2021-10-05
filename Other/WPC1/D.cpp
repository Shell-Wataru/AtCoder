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

using namespace std;
using ll = long long;

vector<ll> prime_numbers(ll n)
{
  if (n <= 1)
  {
    return vector<ll>(0);
  }
  vector<ll> ans = {2};
  for (ll i = 3; i <= n; i++)
  {
    bool is_prime = true;
    for (ll j = 0; ans[j] * ans[j] <= i; j++)
    {
      if (i % ans[j] == 0)
      {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
    {
      ans.push_back(i);
    }
  }
  return ans;
}

void decomposite(ll N, map<ll, ll> &factors, vector<ll> &primes, ll p_index = 0)
{
  if (N == 1)
  {
    return;
  }

  while (primes[p_index] * primes[p_index] <= N)
  {
    if (N % primes[p_index] == 0)
    {
      factors[primes[p_index]] += 1;
      decomposite(N / primes[p_index], factors, primes, p_index);
      return;
    }
    else
    {
      p_index++;
    }
  }
  factors[N] += 1;
}

int main()
{
  // 整数の入力
  ll N, P;
  cin >> N >> P;
  vector<ll> primes = prime_numbers(1000000);
  map<ll, ll> factors;
  decomposite(P, factors, primes);
  ll ans = 1;
  for (auto p : factors)
  {
    ll small = p.second / N;
    ll times = 1;
    for (ll i = 0; i < small; i++)
    {
      times *= p.first;
    }
    ans *= times;
  }
  cout << ans << endl;
  return 0;
}