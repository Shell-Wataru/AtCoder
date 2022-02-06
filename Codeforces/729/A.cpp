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
  ll n,x,t;
  scanf("%lld",&n);
  ll odd = 0;
  for(int i = 0;i < 2*n;i++){
    ll a;
    scanf("%lld",&a);
    if (a % 2 == 1){
      odd++;
    }
  }
  if (odd == n){
    cout << "Yes";
  }else{
    cout << "No";
  }
  cout << "\n";
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