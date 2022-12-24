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
  scanf("%lld", &n);
  if (n % 2 == 1){
    cout << 0 << "\n";
  }else{
    ll ans = 1;
    for(int i = 1;i <= n/2;i++){
      ans = (ans*i) % 998244353;
    }
    cout << (ans * ans )  % 998244353 << "\n";
  }
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