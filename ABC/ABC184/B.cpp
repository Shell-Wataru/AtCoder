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
  ll N,X;
  cin >> N >> X;
  string S;
  cin >> S;
  for(auto c:S){
    if (c == 'o'){
      X++;
    }else{
      X = max(X-1,0ll);
    }
  }
  cout << X << endl;
 return 0;
}