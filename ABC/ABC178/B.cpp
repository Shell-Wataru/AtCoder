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
  // 整数の入力
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll ans = numeric_limits<ll>::min();
  ans = max(ans,a*c);
  ans = max(ans,a*d);
  ans = max(ans,b*c);
  ans = max(ans,b*d);
  cout << ans << endl;
 return 0;
}