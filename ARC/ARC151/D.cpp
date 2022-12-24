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
  modint ans = 0;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
    A[i]--;
  }
  cout << ans << endl;
  return 0;
}