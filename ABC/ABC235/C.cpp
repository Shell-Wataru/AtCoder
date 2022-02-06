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
  ll N,Q;
  cin >> N >> Q;
  map<ll,vector<ll>> indices;
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    indices[a].push_back(i);
  }
  for(int i = 0;i < Q;i++){
    ll x,k;
    cin >> x >> k;
    if (k <= indices[x].size()){
      cout << indices[x][k-1] + 1 << endl;
    }else{
      cout << -1 << endl;
    }
  }
  return 0;
}