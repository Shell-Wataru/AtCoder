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
  ll all_gcd = 0;
  for(int i = 0;i < 30;i++){
    ll count = 0;
    for(int j = 0;j < n;j++){
      if (a[j] & 1ll<<i){
        count++;
      }
    }
    all_gcd = gcd(all_gcd,count);
  }
  for(int i = 1;i <= n;i++){
    if (all_gcd % i == 0){
      cout << i << " ";
    }
  }
  cout << "\n";
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