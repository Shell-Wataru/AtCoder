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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,x,y;
  cin >> N >> x >> y;
  vector<ll> A(N);
  vector<ll> X;
  vector<ll> Y;
  for(int i = 0;i < N;i++){
    cin >> A[i];
    if (i % 2 == 0){
      X.push_back(A[i]);
    }else{
      Y.push_back(A[i]);
    }
  }
  unordered_set<ll> current_xs;
  current_xs.insert(A[0]);
  for(int i = 1;i < X.size();i++){
    unordered_set<ll> next_xs;
    for(auto xx:current_xs){
      next_xs.insert(xx+X[i]);
      next_xs.insert(xx-X[i]);
    }
    swap(current_xs,next_xs);
  }
  unordered_set<ll> current_ys;
  current_ys.insert(0);
  for(int i = 0;i < Y.size();i++){
    unordered_set<ll> next_ys;
    for(auto yy:current_ys){
      next_ys.insert(yy+Y[i]);
      next_ys.insert(yy-Y[i]);
    }
    swap(current_ys,next_ys);
  }
  if (current_xs.count(x) && current_ys.count(y)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}