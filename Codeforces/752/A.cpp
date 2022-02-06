#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll cannot_delete = 1;
  for(ll i = 0;i < n;i++){
    if (cannot_delete < 10000000000ll){
      cannot_delete = cannot_delete * (i+2)/ gcd(cannot_delete,i+2);
    }
    if (a[i] % cannot_delete == 0){
      cout << "NO\n";
      return 0;
    }else{
      continue;
    }
  }
  cout << "YES\n";
  return 0;
}

int main()
{
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