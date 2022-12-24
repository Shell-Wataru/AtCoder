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
  ll N,L;
  cin >> N >> L;
  vector<ll> A(N);
  ll current = 0;
  ll one_count = 0;
  bool can_make = true;
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    if (a == 1){
      if (current == L){
        one_count--;
      }else{
        current += 2;
        one_count++;
      }
    }else{
      if (current == L-2){
        current += 2;
      }else if (current < L-2){
        current += 3;
        one_count++;
      }else{
        can_make = false;
      }
    }
    if (current == L-1){
      one_count++;
      current = L;
    }
  }
  // cout << current << endl;
  if (can_make){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
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