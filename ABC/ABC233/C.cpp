#define _USE_MATH_DEFINES
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

int main()
{
  ll N,X;
  cin >> N >> X;
  vector<ll> Ls(N);
  vector<vector<ll>> balls(N);
  ll total = 1;
  for(int i = 0;i < N;i++){
    cin >> Ls[i];
    total *= Ls[i];
    for(int j = 0;j < Ls[i];j++){
      ll a;
      cin >> a;
      balls[i].push_back(a);
    }
  }
  ll ans = 0;
  for(int i = 0;i < total;i++){
    ll target = X;
    ll number = i;
    bool can_make = true;
    for(int j = 0;j < N;j++){
      // cout << balls[j][number % Ls[j]] << ",";
      ll b = balls[j][number % Ls[j]];
      if (target % b != 0){
        can_make = false;
        // break;
      }else{
        target /= b;
      }
      number /= Ls[j];
    }
    // cout << endl;
    // cout << X << endl;
    if (can_make && target == 1){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}