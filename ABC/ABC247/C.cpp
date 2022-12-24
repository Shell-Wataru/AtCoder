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

vector<string> answers(17);

string ans(ll N){
  if (N == 1){
    return "1";
  }else if (answers[N] != ""){
    return answers[N];
  }else{
    answers[N] = ans(N-1)+ " " + to_string(N) + " " +ans(N-1);
    return answers[N];
  }
}

int main()
{
  ll N;
  cin >> N;
  cout << ans(N) << endl;
  return 0;
}