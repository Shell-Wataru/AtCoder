#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve()
{
  ll a,b;
  cin >> a >> b;
  cout << to_string(a) + "0" + to_string(b*5) << endl;
  return 0;
}
int main()
{
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  // cout << flush;
  return 0;
}