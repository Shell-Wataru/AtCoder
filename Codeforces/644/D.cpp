#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int solve()
{
  ll n, k;
  cin >> n >> k;
  ll max_k = 0;
  for(ll i = 1;i * i <= n;i++ ){
    if (n % i == 0){
      if (i <= k){
        max_k = max(max_k,i);
      }
      if (n/i <= k){
        max_k = max(max_k,n/i);
      }
    }
  }
  cout << n/max_k << endl;


  return 0;
}

int main()
{
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  // cout << flush;
  return 0;
}