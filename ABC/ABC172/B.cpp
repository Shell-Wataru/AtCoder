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
  string S,T;
  cin >> S >> T;
  ll ans = 0;
  for (size_t i = 0; i < S.length(); i++)
  {
    if (S[i] != T[i]){
      ans++;
    }
  }
  cout <<ans << endl;

  return 0;
}