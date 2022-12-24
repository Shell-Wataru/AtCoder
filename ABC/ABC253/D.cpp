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
#include <stack>

using namespace std;
using ll = long long;

int solve()
{
  ll N,A,B;
  cin >> N >> A >> B;
  ll a = N/A;
  ll b = N/B;
  ll lcm_ab= A*B/gcd(A,B);
  ll ab = N/lcm_ab;
  ll all_sum = N*(N+1)/2;
  ll a_sum = a*(a+1)/2 * A;
  ll b_sum = b*(b+1)/2 * B;
  ll ab_sum = ab*(ab+1)/2 * lcm_ab;
  // cout << lcm_ab << endl;
  // cout << all_sum << endl;
  // cout << a_sum << endl;
  // cout << b_sum << endl;
  // cout << ab_sum << endl;
  cout << all_sum - a_sum - b_sum + ab_sum<< endl;
  return 0;
}

int main()
{
  // cout << "!" << endl;
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}
