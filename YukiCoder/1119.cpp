#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll A,B,C;
  cin >> A >> B >> C;
  if (A % 3 != 0 && B % 3 != 0 && C % 3 != 0 ){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  return 0;
}