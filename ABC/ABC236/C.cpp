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
  ll N,M;
  cin >> N >> M;
  vector<string> S(N);
  set<string> T;
  for(int i = 0;i < N;i++){
    cin >> S[i];
  }
  for(int i = 0;i < M;i++){
    string t;
    cin >> t;
    T.insert(t);
  }
  for(int i = 0;i < N;i++){
    if (T.find(S[i]) == T.end()){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
  }
  return 0;
}