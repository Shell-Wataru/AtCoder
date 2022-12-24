#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll g = 0;
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  for(int i = 0;i < N-1;i++){
    g = gcd(g,-A[i]+A[i+1]);
  }
  // cout << g << endl;
  if (g > 1 || g == 0){
    cout << 1 << endl;
  }else{
    cout << 2 << endl;
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