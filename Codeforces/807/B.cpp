#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll total = 0;
  for(int i = 0;i < n;i++){
    cin >> a[i];

  }
  ll not_zero = 0;
  ll zero = 0;
  for(int i = 0;i < n-1;i++){
    total+= a[i];
    if (a[i] > 0){
      not_zero++;
    }
    if (a[i] == 0){
      if (not_zero > 0){
        zero++;
      }
    }
  }
  // cout << total << endl;
  cout << zero + total << endl;
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