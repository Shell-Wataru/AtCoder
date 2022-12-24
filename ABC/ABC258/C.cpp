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
  ll N,Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  ll index = 0;
  for(int i = 0;i < Q;i++){
    ll t,x;
    cin >> t >> x;
    if (t == 1){
      index = (index - x + N )  % N;
    }else{
      cout << S[(index + x - 1) % N] << endl;
    }
  }
  return 0;
}