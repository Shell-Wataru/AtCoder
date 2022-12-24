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
#include <unordered_map>
#include <unordered_set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  string S,T;
  cin >> S >> T;
  for(int i = 0;i < S.size();i++){
    if (S[i] != T[i]){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << T.size() << endl;
  return 0;
}