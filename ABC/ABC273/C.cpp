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
  map<ll,ll> x;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    ll a;
    cin >> a;
    A[i] = a;
    x[a]++;
  }
  ll total = x.size();
  vector<ll> unique_a;
  vector<ll> answers(N);
  ll index = 0;
  for(auto p:x){
    answers[total- index-1] = p.second;
    index++;
  }
  for(int i = 0;i < N;i++){
    cout << answers[i] << endl;
  }
  return 0;
}