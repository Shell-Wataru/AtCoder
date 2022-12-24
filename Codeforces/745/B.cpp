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

vector<ll> xor_sum(1000000,0);
int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  ll total  = 0;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    total += a[i];
  }
  bool can_make = true;
  bool edges_are_one = (a[0] == 1) && (a.back() == 1);
  bool all_pairs = true;
  for(int i = 1;i < n;i+=2){
    if(a[i] != a[i+1]){
      all_pairs = false;
    }
  }
  can_make = !(edges_are_one && all_pairs) && total % 2 == 0;
  if (!can_make){
    cout << "NO\n";
  }else{
    cout << "YES\n";
    if (a[0] == 0){
      for(int i = n;i <)
    }
  }
  return 0;
}

int main()
{
  for(int i = 1;i < 1000000;i++){
    xor_sum[i] = xor_sum[i-1]^i;
  }
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}