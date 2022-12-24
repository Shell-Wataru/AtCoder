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
  ll n,m,k;
  cin >> n >> m >> k;
  vector<ll> a(m);
  for(int i = 0;i < m;i++){
    scanf("%lld",&a[i]);
  }
  ll same_count = 0;
  for(int i = 0;i < m;i++){
    if ((n+k-1)/k < a[i]){
      cout << "No\n";
      return 0;
    }else if ((n+k-1)/k == a[i]){
      same_count++;
    }
  }
  // cout << same_count << endl;
  if (n % k != 0  && same_count > n % k){
    cout << "No\n";
  }else{
    cout << "Yes\n";
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