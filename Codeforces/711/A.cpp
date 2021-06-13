
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

int gcd_sum(ll n){
  ll sum = 0;
  for(auto c:to_string(n)){
    sum += c - '0';
  }
  return gcd(n,sum);
}
int solve()
{
  ll n;
  scanf("%lld",&n);
  ;
  while(true){
    if (gcd_sum(n) > 1){
      break;
    }else{
      n++;
    }
  }
  cout << n << "\n";
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