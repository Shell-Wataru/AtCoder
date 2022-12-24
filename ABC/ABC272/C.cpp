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
  ll N;
  cin >> N;
  vector<ll> odds;
  vector<ll> evens;
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    if (a % 2 == 0){
      evens.push_back(a);
    }else{
      odds.push_back(a);
    }
  }
  sort(evens.rbegin(),evens.rend());
  sort(odds.rbegin(),odds.rend());
  ll ans = -1;
  if (evens.size() >= 2){
    ans = max(ans,evens[0]+evens[1]);
  }
  if (odds.size() >= 2){
    ans = max(ans,odds[0]+odds[1]);
  }
  cout << ans << endl;
  return 0;
}