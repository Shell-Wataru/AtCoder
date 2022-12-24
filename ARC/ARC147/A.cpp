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
  vector<ll> A(N);
  map<ll,ll> counts;
  for(int i = 0;i < N;i++){
    cin >> A[i];
    counts[A[i]]++;
  }
  ll ans = 0;
  while(counts.size() > 1 ||  counts.begin()->second > 1){
    ans++;
    ll a_small =  counts.begin()->first;
    ll a_big =  counts.rbegin()->first;
    ll new_a = a_big % a_small;
    counts[a_big]--;
    if (counts[a_big] == 0){
      counts.erase(a_big);
    }
    if (new_a != 0){
      counts[new_a]++;
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
  cout << flush;
  return 0;
}