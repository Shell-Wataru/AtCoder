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
  scanf("%lld",&n);
  ll X = (1ll<<30) -1;
  for(int i = 0;i < n;i++){
    ll a;
    cin >> a;
    if (a != i){
      X &= a;
    }
  }
  cout << X << "\n";
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