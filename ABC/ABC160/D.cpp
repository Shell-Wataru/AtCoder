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
  ll N, X, Y;
  map<ll, ll> counts;
  cin >> N >> X >> Y;
  X--;Y--;
  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      ll d = min(min((ll)abs(j - i),abs(X-j) + abs(Y- i) + 1), abs(X-i) + abs(Y- j) + 1);
      counts[d]++;
    }
  }

  for(int i = 1;i< N;i++){
    cout << counts[i] << endl;
  }
  return 0;
}