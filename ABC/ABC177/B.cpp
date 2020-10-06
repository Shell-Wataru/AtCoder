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
  string S,T;
  cin >> S >> T;
  ll min_not_matches = numeric_limits<ll>::max();
  for(int i = 0;i + T.length() - 1< S.length();i++){
    ll not_matches = 0;
    for(int j = 0; j < T.length();j++){
      if (S[i+j] != T[j]){
        not_matches++;
      }
    }
    min_not_matches = min(min_not_matches,not_matches);
  }
  cout << min_not_matches << endl;
 return 0;
}