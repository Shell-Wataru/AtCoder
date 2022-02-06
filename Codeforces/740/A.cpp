\

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

bool is_sorted(vector<ll> &a){
  for(int i = 0;i < a.size()-1;i++){
    if (a[i] > a[i+1]){
      return false;
    }
  }
  return true;
}
int solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    a[i]--;
  }
    ll ans = 0;
  while(true){
    if (is_sorted(a)){
      break;
    }
    for(int i = 0;i < n-1;i+= 2){
      if (a[i] > a[i+1]){
        swap(a[i],a[i+1]);
      }
    }
    ans++;
    if (is_sorted(a)){
      break;
    }
    for(int i = 1;i < n-1;i+= 2){
      if (a[i] > a[i+1]){
        swap(a[i],a[i+1]);
      }
    }
    ans++;
  }
  cout << ans << "\n";
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