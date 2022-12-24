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
  ll N;
  cin >> N;
  ll M = 2*N;
  cout << M << endl;
  string ans;
  for(int i = 0;i < N/4;i++){
    ans += '4';
  }
  if (N % 4 != 0){
    ans += '0' + N % 4;
  }
  reverse(ans.begin(),ans.end());
  cout << ans << endl;
  return 0;
}
int main()
{
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}