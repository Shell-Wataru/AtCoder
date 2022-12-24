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
#include <climits>
#include <atcoder/string>

using namespace std;
using ll = long long;
using namespace atcoder;

int solve(){
  ll A,B;
  cin >> A >> B;
  if (A >= B){
    cout << A - B << endl;
  }else{
    ll ans = B-A;
    if (A <= 100000){
      for(int x = 0;x < ans;x++){
        ll y = (B+A+x-1)/(A+x) * (A+x) - B;
        // cout << x << "," << y << endl;
        ans = min(ans,x+y);
      }
      cout << ans << endl;
    }else{
      ll ans = numeric_limits<ll>::max();
      for(int k = 1;B - (k-1)*A  >= 0;k++){
        ll remain = B-k*A;
        if (remain >= 0){
          ll x = (remain+k-1)/k;
          ll y = abs(remain - k * x);
          ans = min(ans,x+y);
        }else{
          ans = min(ans,-remain);
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
int main()
{
    ll N;
    cin >> N;
    for(int i = 0;i < N;i++){
      solve();
    }
    cout << flush;
    return 0;
}