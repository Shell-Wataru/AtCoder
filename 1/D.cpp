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
  vector<string> D(5);
  vector<ll> ans(N);
  for(int i = 0;i < 5;i++){
      cin >> D[i];
  }
  for(int i = 0;i < N;i++){
      ll upleft = 4*i;
      if (D[2][4*i + 2] == '#'){
          if (D[3][4*i + 2] == '#'){
              ans[i] = 1;
          }else if(D[1][4*i+1] == '.' && D[3][4*i+3] == '.'){
              ans[i] = 2;
          }else if(D[1][4*i+1] == '.' && D[3][4*i+1] == '.'){
              ans[i] = 3;
          }else if(D[0][4*i+2] == '.'){
              ans[i] = 4;
          }else if(D[3][4*i+1] == '.' && D[1][4*i+3] == '.'){
              ans[i] = 5;
          }else if(D[1][4*i+3] == '.'){
              ans[i] = 6;
          }else if(D[3][4*i+1] == '.'){
              ans[i] = 9;
          }else{
              ans[i] = 8;
          }
      }else{
          if (D[2][4*i+1] == '.'){
              ans[i] = 7;
          }else{
              ans[i] = 0;
          }
      }
  }
  for(auto a:ans){
      cout << a;
  }
  cout << endl;
 return 0;
}