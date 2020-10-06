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
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (size_t i = 0; i < n; i++)
  {
    scanf("%lld",&A[i]);
  }
  reverse(A.begin(),A.end());
  ll grundy = 0;
  for (size_t i = 0; i < n; i++)
  {
    if (grundy < A[i]){
      grundy = A[i];
    }else{
      grundy = A[i] - 1;
    }
  }
  if (grundy == 0){
    cout << "Second" << endl;
  }else{
    cout << "First" << endl;
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
  return 0;
}
