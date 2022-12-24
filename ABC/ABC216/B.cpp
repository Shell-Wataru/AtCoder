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

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  set<pair<string,string>> names;
  for(int i = 0;i < N;i++){
    string s,t;
    cin >> s >> t;
    if (names.find({s,t}) != names.end()){
      cout << "Yes" << endl;
      return 0;
    }else{
      names.insert({s,t});
    }
  }
  cout << "No" << endl;
  return 0;
}