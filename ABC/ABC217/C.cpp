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
  ll N;
  cin >> N;
  vector<ll> P(N);
  for(int i = 0;i < N;i++){
    ll p;
    cin >> p;
    p--;
    P[p] = i+1;
  }
  for(int i = 0;i < N;i++){
    if (i != 0){
      cout << " ";
    }
    cout << P[i];
  }
  cout << endl;
  return 0;
}