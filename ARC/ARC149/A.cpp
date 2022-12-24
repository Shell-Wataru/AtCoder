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
  ll N,M;
  cin >> N >> M;
  string ans;
  for(int i = 1;i<=9;i++){
    ll mod = 0;
    string current;
    for(int j = 0;j < N;j++){
      mod *= 10;
      mod += i;
      mod %= M;
      current += '0' + i;
      if (mod == 0){
        if (ans.size() <= current.size()){
          ans = current;
        }
      }
    }
  }
  if (ans.empty()){
    cout << -1 << endl;
  }else{
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