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
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
  }
  ll c = -1;
  ll m = numeric_limits<ll>::max()/2;
  for(int i = 0; i < n-1;i++){
    if (a[i] <= a[i+1]){
      c = a[i+1] - a[i];
      break;
    }
  }
  if (c != -1){
    for(int i = 0; i < n-1;i++){
      if (a[i] >  a[i+1]){
        m = a[i] + c - a[i+1];
        break;
      }
    }
  }else{
    for(int i = 0; i < n-1;i++){
      if (a[i] >  a[i+1]){
        c = a[i+1] + m - a[i];
        break;
      }
    }
  }

  bool is_correct = a[0] < m;
  for(int i = 0;i < n-1;i++){
    if (a[i+1] != (a[i]+c) % m){
      is_correct = false;
      break;
    }
  }

  if (!is_correct){
    cout << -1;
  }else if (m == numeric_limits<ll>::max()/2){
    cout << 0;
  }else{
    cout << m << " " << c;
  }
  cout << "\n";
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