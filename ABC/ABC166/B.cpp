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
  set<ll> has;
  for(int i = 0;i < K;i++){
    ll d;
    cin >> d;
    for(int j = 0; j < d;j++){
      ll a;
      cin >> a;
      has.insert(a);
    }
  }
  cout << N - has.size() << endl;
  return 0;
}