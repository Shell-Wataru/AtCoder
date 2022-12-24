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
  scanf("%lld",&x);
  scanf("%lld",&y);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i = 0;i < n;i++){
    x += a[i];
  }
  // cout << x << endl;
  if ( x % 2 == y % 2){
    cout << "Alice";
  }else{
    cout << "Bob";
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