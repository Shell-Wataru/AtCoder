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
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;
int main()
{
  // 整数の入力
  string S;
  cin >> S;
  vector<vector<ll>> DP(2,vector<ll>(2019,0));
  ll total = 0;
  for(int i = 0 ;i < S.size();i++){
    ll a = S[i] - '0';
    DP[(i+1)% 2] = vector<ll>(2019,0);
    for(int j = 0;j < 2019;j++){
      DP[(i+1) % 2][(j * 10 + a) % 2019] += DP[i % 2][j];
    }
    DP[(i+1) % 2][a] += 1;
    // cout << DP[(i+1) % 2][0] << endl;
    total += DP[(i+1) % 2][0];
  }
  // cout << endl;
  cout << total << endl;
  return 0;
}