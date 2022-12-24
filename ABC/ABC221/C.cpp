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
  string N;
  cin >> N;
  ll n = N.size();
  ll ans = 0;
  for(int i = 0;i < 1ll<<n;i++){
    vector<ll> a;
    vector<ll> b;
    for(int j = 0;j < n;j++){
      if (i & 1ll<<j){
        a.push_back(N[j] - '0');
      }else{
        b.push_back(N[j] - '0');
      }
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    ll a_value = 0;
    for(auto aa:a){
      a_value *= 10;
      a_value += aa;
    }
    ll b_value = 0;
    for(auto bb:b){
      b_value *= 10;
      b_value += bb;
    }
    ans = max(ans,a_value*b_value);
  }
  cout << ans << endl;
  return 0;
}