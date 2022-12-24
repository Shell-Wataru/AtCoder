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
  ll N,L,W;
  cin >> N >> L >> W;
  vector<ll> a(N);
  for(int i = 0;i < N;i++){
    cin >> a[i];
  }
  a.push_back(L);
  ll last = 0;
  ll a_index = 0;
  ll ans = 0;
  while(last < L){
    if (a[a_index] <= last){
      last = max(last,a[a_index] + W);
      a_index++;
    }else{
      ll new_items = (a[a_index] - last + W-1)/W;
      ans += new_items;
      last += new_items * W;
    }
  }
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
  // cout << flush;
  return 0;
}