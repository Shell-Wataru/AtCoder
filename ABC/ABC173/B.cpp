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
  // 整数の入力
  ll N;
  cin >> N;
  map<string,ll> ans;
  for (size_t i = 0; i < N; i++)
  {
    string s;
    cin >> s;
    ans[s]++;
  }
  cout << "AC x " << ans["AC"] << endl;
  cout << "WA x " << ans["WA"] << endl;
  cout << "TLE x " << ans["TLE"] << endl;
  cout << "RE x " << ans["RE"] << endl;
  return 0;
}