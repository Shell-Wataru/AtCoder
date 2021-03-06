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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N;
  vector<ll> counts(200,0);
  cin >> N;
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    counts[a%200]++;
  }
  ll ans = 0;
  for(int i = 0;i < 200;i++){
    ans += counts[i]* (counts[i]-1)/2;
  }
  cout << ans << endl;
  return 0;
}