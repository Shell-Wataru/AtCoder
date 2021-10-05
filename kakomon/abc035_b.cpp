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
  string S;
  cin >> S;
  ll x = 0;
  ll y = 0;
  ll hatena = 0;
  for(auto c:S){
      if (c == 'L'){
          x--;
      }else if(c == 'R'){
          x++;
      }else if(c == 'U'){
          y++;
      }else if(c == 'D'){
          y--;
      }else{
          hatena++;
      }
  }
  ll t;
  cin >> t;
  if (t == 1){
      cout << abs(x) + abs(y) + hatena << endl;
  }else{
      ll remain = abs(x) + abs(y) - hatena;
      if (remain >= 0){
          cout << remain << endl;
      }else{
          if (S.size() % 2 == 0){
              cout << 0 << endl;
          }else{
              cout << 1 << endl;
          }
      }
  }
  return 0;
}