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
int BASE_NUM = 998244353;

int solve()
{
  ll  n;
  scanf("%lld",&n);
  vector<ll> A(n);
  vector<ll> B(n);
  vector<ll> C(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&A[i]);
  }
  vector<ll> counts(20,0);
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < 20; j++)
    {
      if (A[i] & 1<<j){
        counts[j]++;
      }
    }
  }
  ll sum = 0;
  for (size_t i = 0; i < n; i++)
  {
    ll a = 0;
    for (size_t j = 0; j < 20; j++)
    {
      if (counts[j]> 0){
        a += 1<<j;
        counts[j]--;
      }
    }
    sum+= a*a;
  }
  cout << sum << endl;
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
  // cout << flush;
  return 0;
}