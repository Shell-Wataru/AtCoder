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

int main()
{
  string S;
  cin >> S;
  sort(S.begin(),S.end());
  ll K;
  cin >> K;
  for(int i = 0;i < K-1;i++){
      next_permutation(S.begin(),S.end());
  }
  cout << S << endl;
  return 0;
}