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
  ll A,B,C;
  cin >> A >> B >> C;
  if (C % 2 == 0){
      if (abs(A) == abs(B)){
          cout << "=" << endl;
      }else if (abs(A)  > abs(B)){
          cout << ">" << endl;
      }else{
          cout << "<" << endl;
      }
  }else{
      if (A == B){
          cout << "=" << endl;
      }else if (A  > B){
          cout << ">" << endl;
      }else{
          cout << "<" << endl;
      }
  }
  return 0;
}