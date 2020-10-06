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
  // 整数の入力
  ll N;
  cin >> N;
  ll ans = 0;
  for(int i = 1;i <= N;i++){
    ll count = N/i;
    ans += i * count * (count + 1)/2;
  }
  cout << ans << endl;
  return 0;
}