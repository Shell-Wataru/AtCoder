#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  ll n,a,b;
  scanf("%lld",&n);
  scanf("%lld",&a);
  scanf("%lld",&b);
  ll x = 1;
  while(x <= n){
    if ( (n - x) % b == 0){
      cout << "Yes\n";
      return 0;
    }else if (a != 1){
      x *= a;
    }else{
      break;
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