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

vector<ll> xor_sum(1000000,0);
int solve()
{
  ll a,b;
  scanf("%lld", &a);
  scanf("%lld", &b);
  ll target  = xor_sum[a-1]^b;
  // cout << "a:" << a << endl;
  // cout << "b:" << b << endl;
  // cout << "total:" << total << endl;
  // cout << "target:" << target << endl;
  if (target == 0){
    cout << a << "\n";
  }else if (target != a){
    cout << a + 1 << "\n";
  }else{
    cout << a + 2 << "\n";
  }
  return 0;
}

int main()
{
  for(int i = 1;i < 1000000;i++){
    xor_sum[i] = xor_sum[i-1]^i;
  }
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}