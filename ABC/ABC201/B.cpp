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
  ll N,K;
  cin >> N >> K;
  ll ans = 0;
  for(int i = 1;i <= N;i++){
    for(int j = 1; j <= K;j++){
      ans += stoll(to_string(i) + "0" + to_string(j));
    }
  }
  cout << ans << endl;
  return 0;
}