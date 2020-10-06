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

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> A(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&A[i]);
  }
  ll max_value = numeric_limits<ll>::min();
  ll min_value = numeric_limits<ll>::max();
  for (size_t i = 0; i < n; i++)
  {
    max_value = max(max_value,A[i]);
    min_value = min(min_value,A[i]);
  }
  if (k % 2 == 1){
    for (size_t i = 0; i < n; i++)
    {
      if (i != 0){
        cout << " ";
      }
      cout << max_value - A[i];
    }
  }else{
    for (size_t i = 0; i < n; i++)
    {
      if (i != 0){
        cout << " ";
      }
      cout << A[i] - min_value;
    }
  }
  cout << endl;
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
