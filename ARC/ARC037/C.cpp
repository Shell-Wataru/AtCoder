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
namespace mp = boost::multiprecision;

using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;

ll count(ll n,vector<ll> &A,vector<ll> &B){
  ll ans = 0;
  for(auto a:A){
    ll x = (n+ a -1)/a;
    ans += lower_bound(B.begin(),B.end(),x) - B.begin();
  }
  // cout << n <<":" << ans << endl;
  return ans;
}
ll kth_numer(ll k,vector<ll> &A,vector<ll> &B,ll l,ll r){
  if (l + 1 == r){
    return l;
  }
  ll center =(l+r)/2;
  if (count(center,A,B) >= k){
    return kth_numer(k,A,B,l,center);
  }else{
    return kth_numer(k,A,B,center,r);
  }

}
int main()
{
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N),B(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (size_t i = 0; i < N; i++)
  {
    cin >> B[i];
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  cout << kth_numer(K,A,B,0,numeric_limits<ll>::max()) << endl;
  return 0;
}