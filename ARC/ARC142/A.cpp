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
  string sK = to_string(K);
  reverse(sK.begin(),sK.end());
  ll revK = stoll(sK);
  reverse(sK.begin(),sK.end());
  ll revrevK = stoll(sK);
  if (revK < K || revrevK < K){
    cout << 0 << endl;
    return 0;
  }else{
    ll ans = 0;
    if (K != revK){
      while(K <= N){
        ans++;
        K *= 10;
      }
      while(revK <= N){
        ans++;
        revK *= 10;
      }
    }else{
      while(K <= N){
        ans++;
        K *= 10;
      }
    }
    cout << ans << endl;
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