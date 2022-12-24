#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  ll k;
  scanf("%lld", &n);
  scanf("%lld", &k);
  vector<ll> a(n);
  set<ll> exists;
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
    exists.insert(a[i]);
  }
  for(auto aa:a){
    if (exists.find(aa+k) != exists.end() || exists.find(aa-k) != exists.end()){
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}