
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
  bool can_make = true;
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
    if (a[i] < 0){
      can_make = false;
    }
  }
  if (can_make){
    cout << "Yes\n101\n";
    for(int i = 0;i <= 100;i++){
      if (i!=0){
        cout << " ";
      }
      cout << i;
    }
    cout << "\n";
  }else{
    cout << "No\n";
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