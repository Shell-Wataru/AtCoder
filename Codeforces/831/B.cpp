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
  ll max_height = 0;
  ll total_width = 0;
  for(int i = 0 ;i < n;i++){
    ll a,b;
    cin >> a >> b;
    if (a > b){
      swap(a,b);
    }
    total_width += a;
    max_height = max(max_height,b);
  }
  cout << 2*total_width + 2* max_height << "\n";
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