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
  ll removed_count = 0;
  while(!S.empty() && S.back() == 'a'){
    S.pop_back();
    removed_count++;
  }

  reverse(S.begin(),S.end());
  ll rev_removed_count = 0;
  while(!S.empty() && S.back() == 'a'){
    S.pop_back();
    rev_removed_count++;
  }
  string revS(S);
  reverse(S.begin(),S.end());
  if (S == revS && rev_removed_count <= removed_count){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}