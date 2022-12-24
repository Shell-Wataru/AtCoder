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
  ll X,A,D,N;
  cin >> X >> A >> D >> N;
  if (X <= min(A,A + D*(N-1))){
    cout << min(A,A + D*(N-1))-X << endl;
  }else if (X >= max(A,A + D*(N-1))){
    cout << X - max(A,A + D*(N-1)) << endl;
  }else{
    X -= A;
    X = abs(X);
    D = abs(D);
    cout << min(X % D, D - X % D) << endl;
  }
   return 0;
}