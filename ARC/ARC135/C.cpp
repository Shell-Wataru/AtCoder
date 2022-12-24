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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

vector<ll> count_bits(ll N, vector<ll> &A)
{
  vector<ll> counts(30, 0);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 30; j++)
    {
      if (A[i] & 1ll << j)
      {
        counts[j]++;
      }
    }
  }
  return counts;
}

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  vector<ll> counts = count_bits(N, A);

  for (int i = 29; i >= 0; i--)
  {
    ll not_change_mask = 0;
    ll change_mask = 0;
    for (int j = 29; j >= 0; j--)
    {
      if (2 * counts[j] < N)
      {
        change_mask += 1ll << j;
      }
      else if (2 * counts[j] > N)
      {
        not_change_mask += 1ll << j;
      }
    }
    ll reverse_index = -1;
    ll maximum_change = 0;
    for (int j = 0; j < N; j++)
    {
      if ((change_mask & A[j]) > (not_change_mask & A[j]))
      {
        if ((change_mask & A[j]) > maximum_change)
        {
          reverse_index = j;
          maximum_change = (change_mask & A[j]);
        }
      }
    }
    if (reverse_index != -1)
    {
      for (int j = 0; j < N; j++)
      {
        if (j == reverse_index)
        {
          continue;
        }
        A[j] ^= A[reverse_index];
      }
      A[reverse_index] = 0;
      counts = count_bits(N, A);
    }
  }
  ll ans = 0;
  for (auto a : A)
  {
    // cout << bitset<8>(a) << "\n";
    ans += a;
  }
  // cout << endl;
  cout << ans << endl;
  return 0;
}
