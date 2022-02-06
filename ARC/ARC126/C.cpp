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

int main()
{
  ll N,K;
  cin >> N >> K;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  vector<ll> ruisekiWa(N+1,0);
  for(int i = 0;i < N;i++){
    ruisekiWa[i+1] +=ruisekiWa[i] + A[i];
  }
  if (K >=  N* A.back() - ruisekiWa.back()){
    K -= N* A.back() - ruisekiWa.back();
    cout << A.back() + K/N << endl;
  }else{
    ll ans = 1;
    for(ll i = 2;i < A.back();i++){
      ll k = 0;
      for(int j = 1;i*(j-1) < A.back();j++){
        ll l = upper_bound(A.begin(),A.end(),i*(j-1)) - A.begin();
        ll r = upper_bound(A.begin(),A.end(),i*j) - A.begin();
        k += i*j *(r-l) - (ruisekiWa[r] - ruisekiWa[l]);
      }
      if (k <= K){
        ans = max(ans,i);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
