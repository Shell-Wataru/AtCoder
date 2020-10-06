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
  ll N,K;
  cin >> N >> K;
  vector<ll> P(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> P[i];
  }
  sort(P.begin(),P.end());
  ll ans = 0;
  for (size_t i = 0; i < K; i++)
  {
    ans += P[i];
  }
  cout <<ans << endl;

  return 0;
}