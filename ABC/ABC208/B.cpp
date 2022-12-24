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
  ll P;
  cin >> P;
  ll ans = 0;
  ll coin = 1*2*3*4*5*6*7*8*9*10;
  while(P > 0){
    for(int i = 10;i >= 1;i--){
      while(P >= coin){
        P -= coin;
        ans++;
      }
      coin /= i;
    }
  }
  cout << ans << endl;
  return 0;
}