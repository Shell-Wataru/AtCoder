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

bool is_same1(vector<ll> &X){
  for(int i = 1;i < X.size();i++){
    if (X[i] != X[0]){
      return false;
    }
  }
  return true;
}

bool is_order(vector<ll> &X){
  for(int i = 1;i < X.size();i++){
    if (X[i] != (X[0] + i) % 10){
      return false;
    }
  }
  return true;
}
int main()
{
  // 整数の入力
  vector<ll> X(4);
  for(int i = 0;i < 4;i++){
    char x;
    cin >> x;
    X[i]= x -'0';
  }
  if (is_order(X) || is_same1(X) ){
    cout << "Weak" << endl;
  }else{
    cout << "Strong" << endl;
  }
  return 0;
}