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

int solve()
{
  ll n;
  scanf("%lld", &n);
  vector<ll> a(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&a[i]);
  }
  ll min_index = min_element(a.begin(),a.end()) - a.begin();
  ll min_value = a[min_index];
  cout << n - 1 << "\n";
  for(int i = min_index - 1;i >= 0;i--){
    cout << i+1 << " " << min_index+1 << " " << min_value + abs(min_index - i) << " " << min_value << "\n";
  }
  for(int i = min_index + 1;i < n;i++){
    cout << i+1 << " " << min_index+1 << " " << min_value + abs(min_index - i) << " " << min_value << "\n";
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