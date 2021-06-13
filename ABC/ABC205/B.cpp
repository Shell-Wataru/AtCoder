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
  set<ll> s;
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    s.insert(a);
  }
  if (s.size() == N &&  *s.begin() == 1 && *s.rbegin() == N){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}