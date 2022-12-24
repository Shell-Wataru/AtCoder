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
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  if (n == 1){
    cout << 1 << "\n";
  }else if (n % 2 == 1){
    cout << n << "\n";
  }else{
    bool zebra = true;
    for(int i = 0;i < n;i++){
      if (a[i] != a[(i+2)%n]){
        zebra = false;
      }
    }
    if (zebra){
      cout << n/2 + 1 << "\n";
    }else{
      cout << n << "\n";
    }
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