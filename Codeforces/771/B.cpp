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
  ll n,x,y;
  scanf("%lld",&n);
  vector<ll> a(n);
  bool odd_sorted = true;
  bool even_sorted = true;
  ll odd_last = -1;
  ll even_last = -1;
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < n;i++){
    if (a[i] % 2 == 0){
      if (a[i] < even_last){
        even_sorted = false;
      }
      even_last = a[i];
    }else if (a[i] % 2 == 1){
      if (a[i] < odd_last){
        odd_sorted = false;
      }
      odd_last = a[i];
    }
  }
  // cout << x << endl;
  if ( even_sorted && odd_sorted){
    cout << "Yes";
  }else{
    cout << "No";
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
  return 0;
}