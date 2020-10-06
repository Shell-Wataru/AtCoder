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
  ll N,D;
  cin >> N;
  cin >> D;
  ll ans = 0;
  for(int i = 0; i < N;i++){
    ll a,b;
    cin >> a >> b;
    if (a*a + b*b <= D*D){
      ans++;
    }
  }
  cout << ans << endl;
 return 0;
}