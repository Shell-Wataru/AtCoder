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
  ll N;
  cin >> N;
  ll m = 0 ,e = 0,c = 0;
  for (size_t i = 0; i < N; i++)
  {
    ll x;
    cin >> x;
    m += abs(x);
    e += x*x;
    c = max(c,abs(x));
  }
  cout << m << endl;
  cout << fixed << setprecision(12) << sqrt(e) << endl;
  cout << c << endl;

 return 0;
}