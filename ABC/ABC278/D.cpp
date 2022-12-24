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
#include <unordered_set>
#include <unordered_map>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,Q;
  cin >> N;
  ll base = 0;
  ll base_changed = -1;
  vector<pair<ll,ll>> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i].first;
    A[i].second = -1;
  }
  cin >> Q;
  for(int i = 0;i < Q;i++){
    ll t;
    cin >> t;
    if (t == 1){
      ll x;
      cin >> x;
      base = x;
      base_changed = i;
    }else if(t == 2){
      ll index,x;
      cin >> index >> x;
      index--;
      if (A[index].second >= base_changed){
        A[index].first += x;
      }else{
        A[index] = {x,i};
      }

    }else{
      ll index;
      cin >> index;
      index--;
      // cout << "b:" << base << endl;
      if (A[index].second >= base_changed){
        cout << base + A[index].first << endl;
      }else{
        cout << base << endl;
      }
    }
  }
  return 0;
}