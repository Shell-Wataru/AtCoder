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
  ll N;
  cin >> N;
  char caa,cab,cba,cbb;
  cin >> caa >> cab >> cba >> cbb;
  if (caa == 'A' && cbb == 'B'){
    cout << N - 1 << endl;
  }else if (caa == 'A' && cab == 'A'){
    cout << 1 << endl;
  }else if (cab == 'B' && cbb == 'B'){
    cout << 1 << endl;
  }else if (caa == 'A' && cab == 'B' && cba == 'A' && cbb == 'A'){
  }
  return 0;
}