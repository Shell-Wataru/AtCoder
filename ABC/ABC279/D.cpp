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

double value(ll A,ll B,ll g)
{
    return B*(g-1)+1.0*A/sqrt(g);
}

int main()
{
  ll A,B;
  cin >> A >> B;
  ll g1 = pow(1.0*A/(2*B),2.0/3);
  double  ans = min(value(A,B,g1),value(A,B,g1+1));
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}