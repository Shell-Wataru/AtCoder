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
  string X;
  ll N;
  cin >> X;
  cin >> N;
  map<char,ll> mapping;
  for(int i = 0;i <26;i++){
    mapping[X[i]] = i;
  }
  vector<vector<ll>> sa(N);
  for(int i = 0;i < N;i++){
    string S;
    cin >> S;
    for(auto c:S){
      sa[i].push_back(mapping[c]);
    }
  }
  sort(sa.begin(),sa.end());
  for(int i = 0;i < N;i++){
    for(auto j:sa[i]){
      cout << X[j];
    }
    cout << endl;
  }
  return 0;
}