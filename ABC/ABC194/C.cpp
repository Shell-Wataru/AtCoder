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


const long long BASE_NUM = 1000000007;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll s = 0;
  ll s2 = 0;
  for(int i= 0;i < N;i++){
    ll a;
    cin >> a;
    s += a;
    s2 += a*a;
  }
  cout << N * s2 - s* s << endl;
  return 0;
}