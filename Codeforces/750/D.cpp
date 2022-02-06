#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n,m;
  scanf("%lld", &n);
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll total = 0;
  for(int i = 0;i < n-1;i++){
    if (total >= 0){
      if (a[i] > 0){
        b[i] = -1;
        total -= a[i];
      }else{
        b[i] = 1;
        total += a[i];
      }
    }else{
      if (a[i] < 0){
        b[i] = -1;
        total -= a[i];
      }else{
        b[i] = 1;
        total += a[i];
      }
    }
  }
  if (total == 0){
    b[0] *= 2;
    if (b[0] < 0){
      total -= a[0];
    }else{
      total += a[0];
    }
  }
  ll times = a[n-1]/gcd(total,a[n-1]);
  ll sum = 0;
  for(int i = 0;i < n-1;i++){
    cout << b[i]*times << " ";
    // sum += a[i]*b[i]*times;
  }
  // sum += -total/gcd(total,a[n-1])*a[n-1];
  cout << -total/gcd(total,a[n-1]) << "\n";
  // cout << sum << endl;
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}
