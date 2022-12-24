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
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> maxA(N,0);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }

  for(int i = K;i < N;i++){
    maxA[i] = max(maxA[i-1],A[i]);
  }
  ll ans = numeric_limits<ll>::max();
  for(int i = 0;i< K;i++){
    auto iter = upper_bound(maxA.begin(),maxA.end(),A[i]);
    if (iter != maxA.end()){
      ll j = iter - maxA.begin();
      // cout << i << "," << j << endl;
      ans = min(ans, j - i );
    }
  }
  if (ans != numeric_limits<ll>::max()){
    cout << ans << endl;
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
  // cout << flush;
  return 0;
}