
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  ll total = 0;
  for(int i = 0;i < n;i++){
    ll a;
    cin >> a;
    total += a;
  }
  if (total - n > 0){
    cout << total  -n << endl;
  }else if (total - n == 0){
    cout << 0 << endl;
  }else{
    cout << 1 << endl;
  }
  return 0;
}

int main()
{
  // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
  solve();
  }
  cout << flush;
  return 0;
}