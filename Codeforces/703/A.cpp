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

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> h(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&h[i]);
  }
  ll remains = 0;
  bool can_make = true;
  for(int i = 0;i < n;i++){
    remains += h[i];
    remains -= i;
    if (remains < 0){
      can_make = false;
    }
  }
  if (can_make){
    cout << "YES" << "\n";
  }else{
    cout << "NO" << "\n";
  }
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