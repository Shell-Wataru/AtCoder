#define _USE_MATH_DEFINES
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
#include <unordered_set>
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

unordered_map<ll,ll> cache;
ll f(ll N){
  if (N == 0){
    return 1;
  }else if (cache.count(N)){
    return cache[N];
  }else{
    ll ans = f(N/2) + f(N/3);
    cache[N] = ans;
    return ans;
  }
}
int main()
{
  ll N,x,y;
  cin >> N;
  cout << f(N) << endl;
  return 0;
}