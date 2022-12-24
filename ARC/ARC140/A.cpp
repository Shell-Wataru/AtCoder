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
  string S;
  cin >> S;
  for(int i = 1;i <= N;i++){
    if (N % i != 0){
      continue;
    }
    vector<map<ll,ll>>  counts(i);
    for(int j = 0;j < N;j++){
      counts[j %i][S[j] - 'a']++;
    }
    ll change = 0;
    for(int j = 0;j < i;j++){
      ll maximum = 0;
      for(auto p:counts[j]){
        maximum = max(maximum,p.second);
      }
      change += N/i - maximum;
    }
    if (change <= K){
      cout << i << endl;
      return 0;
    }
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