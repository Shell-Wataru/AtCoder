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

vector<ll> xor_sum(1000000, 0);
int solve()
{
  ll n, x;
  scanf("%lld", &n);
  scanf("%lld", &x);
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
  }
  ll inner_l = n - x;
  ll inner_r = x;
  if (inner_l >= inner_r){
    cout << "Yes\n";
    return 0;
  }
  // cout << inner_l << "~" << inner_r << endl;
  bool can_make = true;
  for (int i = inner_l; i < inner_r - 1; i++)
  {
    if (a[i] > a[i + 1])
    {
      can_make = false;
    }
  }
  ll inner_min = a[inner_l];
  ll inner_max = a[inner_r-1];
  ll smaller_count = 0;
  ll bigger_count = 0;
  for(int i = 0;i < n;i++){
    if(i < inner_l || inner_r <= i){
      if (a[i] <= inner_min ){
        smaller_count++;
      }
      if(a[i] >= inner_max){
        bigger_count++;
      }
    }
  }

  if (can_make && smaller_count >= inner_l && bigger_count >= n - inner_r){
    cout << "Yes\n";
  }else{
    cout << "No\n";
  }
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