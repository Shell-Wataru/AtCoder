#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

vector<ll> prime_numbers(int n)
{
  if (n <= 1)
  {
    return vector<ll>(0);
  }
  vector<ll> ans = {2};
  for (int i = 3; i <= n; i++)
  {
    bool is_prime = true;
    for (int j = 0; ans[j] * ans[j] <= i; j++)
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
vector<ll> primes = prime_numbers(32000);
void decomposite(int N, map<ll, int> &factors, int p_index = 0)
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
      decomposite(N / primes[p_index], factors, p_index);
      return;
    }
    else
    {
      p_index++;
    }
  }
  factors[N] += 1;
}

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);

  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
  }
  unordered_set<ll> remains;
  unordered_set<ll> used;
  for (auto p : primes)
  {
    for (int i = 0; i < n; i++)
    {
      if (a[i] % p == 0)
      {
        if (used.count(p))
        {
          cout << "Yes\n";
          return 0;
        }
        else
        {
          used.insert(p);
        }
      }
      while (a[i] % p == 0)
      {
        a[i] /= p;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (a[i] != 1)
    {
      if (remains.count(a[i]))
      {
        cout << "Yes\n";
        return 0;
      }
      else
      {
        remains.insert(a[i]);
      }
    }
  }
  cout << "No\n";
  return 0;
}

int main()
{
  // cout << primes.size() << endl;
  // cout << primes.back()*primes.back() << endl;
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
