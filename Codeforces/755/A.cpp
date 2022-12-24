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
  vector<ll> b(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < n;i++){
    scanf("%lld",&b[i]);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  ll can_make = true;
  for(int i = 0;i < n;i++){
    if (a[i] == b[i] || a[i] + 1 == b[i]){

    }else{
      can_make = false;
    }
  }
  if (can_make){
    cout << "Yes\n";
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