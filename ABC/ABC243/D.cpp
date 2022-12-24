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
#include <stack>

using namespace std;
using ll = long long;

int solve()
{
  ll N,X;
  cin >> N >> X;
  string S;
  cin >> S;
  string result;
  for(auto c:S){
    if (c == 'U'){
      if (result.empty()){
        X /= 2;
      }else{
        result.pop_back();
      }
    }else{
      result.push_back(c);
    }
  }
  for(auto c:result){
    if (c == 'U'){
      X /= 2;
    }else if (c == 'L'){
      X = 2*X;
    }else {
      X = 2*X + 1;
    }
  }
  cout << X << endl;
  return 0;
}

int main()
{
  // 整数の入力
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  // cout << flush;
  return 0;
}
