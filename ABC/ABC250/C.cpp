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
  vector<ll> A(N);
  vector<ll> revA(N);
  iota(A.begin(),A.end(),0);
  iota(revA.begin(),revA.end(),0);
  for(int i = 0;i < Q;i++){
    ll x;
    cin >> x;
    x--;
    ll current_index = revA[x];
    ll next_index;
    if (current_index == N-1){
      next_index = current_index-1;
    }else{
      next_index = current_index+1;
    }
    ll next_value = A[next_index];
    swap(A[current_index],A[next_index]);
    revA[x] = next_index;
    revA[next_value] = current_index;
    // for(auto a:A){
    //   cout << a + 1 << " ";
    // }
    // cout << endl;
  }
  for(auto a:A){
    cout << a + 1 << " ";
  }
  cout << endl;
  return 0;
}