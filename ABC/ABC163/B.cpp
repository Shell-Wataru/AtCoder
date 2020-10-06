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
  ll N, M;
  cin >> N >> M;
  ll total = 0;
  for (int i = 0; i < M; i++)
  {
    ll a;
    cin >> a;
    total += a;
  }
  if (total > N)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << N - total << endl;
  }
  return 0;
}