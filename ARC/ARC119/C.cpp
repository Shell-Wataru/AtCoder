#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;
  ll total = 0;
  map<ll,ll> count;
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    if (i % 2 == 0){
      total += a;
    }else{
      total -= a;
    }
    count[total]++;
  }
  ll ans = 0;
  for(auto &p:count){
    // cout << p.first  << ":" << p.second << endl;
    if (p.first == 0){
      ans += p.second * (p.second + 1)/2;
    }else{
      ans += p.second * (p.second - 1)/2;
    }

  }
  cout << ans << endl;
  // ll a = 0;
  // for(auto u:used){
  //   a = gcd(a,u);
  // }
  // cout << a << endl;
  // cout << N << endl;
  return 0;
}