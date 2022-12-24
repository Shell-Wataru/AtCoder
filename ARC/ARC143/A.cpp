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
  vector<ll> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(),A.end());
  ll total = 0;
  ll a = A[2] - A[0];
  A[2] -= a;
  A[1] -= a;
  total += a;
  ll b = A[2] - A[1];
  A[0] -= b;
  A[2] -= b;
  total += b;
  if (A[0] >= 0){
    cout << total +  A[0] << endl;
  }else{
    cout << -1 << endl;
  }
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