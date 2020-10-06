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
ll BASE_NUM = 1000000007;

int main()
{
  ll N;
  cin >> N;
  string ans = "";
  while(true){
    N--;
    ll a = N % 26;
    ans += 'a' + a;
    N = N/26;
    if (N == 0){
      break;
    }
  }
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}