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
  for(int i = 0;i < n;i++){
    ll a;
    scanf("%lld",&a);
  }
  cout << 3 * n << "\n";
  for(int i = 0;i < n;i += 2){
    cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
    cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
    cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
    cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
    cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
    cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
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