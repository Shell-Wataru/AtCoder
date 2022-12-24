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

int solve()
{
  ll n;
  scanf("%lld", &n);
  ll ones = 0;
  ll zeros = 0;
  for(int i = 0;i < n;i++){
    ll a;
    scanf("%lld",&a);
    if (a == 0){
      zeros++;
    }else if(a == 1){
      ones++;
    }
  }
  cout << ones*(1ll<<zeros) << "\n";
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