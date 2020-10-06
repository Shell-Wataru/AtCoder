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
  // 整数の入力
  ll N;
  cin >> N;
  string S;
  cin >> S;
  deque<pair<char,ll>> A;
  for (size_t i = 0; i < N; i++)
  {
      if (A.empty()){
        A.push_back({S[i],1});
      }else if (A.back().first == S[i]){
        A.back().second++;
      }else{
        A.push_back({S[i],1});
      }
  }
  ll ans = 0;
  while(!A.empty()){
    if (A.back().first == 'W'){
      A.pop_back();
    }else if (A.front().first == 'R'){
      A.pop_front();
    }else{
      ll utikeshi = min(A.front().second,A.back().second);
      A.front().second -= utikeshi;
      A.back().second -= utikeshi;
      ans += utikeshi;
      if (A.front().second == 0){
        A.pop_front();
      }
      if (A.back().second == 0){
        A.pop_back();
      }
    }
  }
  cout << ans << endl;
 return 0;
}
