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
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  ll count = 0;
  for(int i = 1;i < n-1;i++){
    if (a[i] > a[i-1] && a[i] > a[i+1]){
      if (i+2 < n){
        a[i+1] = max(a[i],a[i+2]);
      }else{
        a[i+1] = a[i];
      }

      count++;
    }
  }
  cout << count << endl;
  for(int i = 0;i < n;i++){
    cout << a[i] << " ";
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